#include <cstdio>
#include <iostream>
using namespace std;
 
const int MAXNODES = 10000;       
   
int gNodeId[MAXNODES], gEdgeId[MAXNODES];
int gNoOfNodes, gEdgeCount;
char input[15];
 
struct tNodeEdge {
     int uToNode;
     int uEdgeWeight;
     int uNextNode;                     
};

struct tNodeEdge gNodeEdge [2 * MAXNODES];

struct tTreeNode {
    int uSubTreeSize;
    int uParentNode;
    int uDepth;
    int uChildNode;
    int uCost;
};

struct tTreeNode gQTree [MAXNODES];

int gSegmentTree[MAXNODES * 8];

inline void IncludeEdge(int beginnode, int endnode, int weight) {

     gNodeEdge[gEdgeCount].uToNode = endnode;
     gNodeEdge[gEdgeCount].uEdgeWeight = weight; 
     gNodeEdge[gEdgeCount].uNextNode = gNodeId[beginnode]; 
     gNodeId[beginnode] = gEdgeCount++;

     gNodeEdge[gEdgeCount].uToNode = beginnode;
     gNodeEdge[gEdgeCount].uEdgeWeight = weight; 
     gNodeEdge[gEdgeCount].uNextNode = gNodeId[endnode]; 
     gNodeId[endnode] = gEdgeCount++;
}
 

 
void AdjustWeight(int pos, int left, int right, int a, int val) {
      if(a <= left && right <= a) gSegmentTree[pos] = val;
      else {
          int ll = pos << 1, rr = ll ^ 1;
          int mid = (left + right) >> 1;
          if(a <= mid) AdjustWeight(ll, left, mid, a, val);
          if(mid < a) AdjustWeight(rr, mid + 1, right, a, val);
          gSegmentTree[pos] = max(gSegmentTree[ll], gSegmentTree[rr]);
      }
}
  
int Query(int pos, int left, int right, int a, int b) {
      if(a <= left && right <= b) return gSegmentTree[pos];
      else {
          int ll = pos << 1, rr = ll ^ 1;
          int mid = (left + right) >> 1, ret = 0;
          if(a <= mid) ret = max(ret, Query(ll, left, mid, a, b));
          if(mid < b) ret = max(ret, Query(rr, mid + 1, right, a, b));
          return ret;
      }
}
  
int gSegTreeID[MAXNODES], gTopNode[MAXNODES], gSegmentTreeNode;

/** 
 * @brief To set the propertes of nodes such as size, depth, 
 *        parent and child in QTREE
 */
void DepthFirstSearch(int currentnode, int parentnode, int depth) {

            int maxsize = 0;

      gQTree[currentnode].uParentNode = parentnode;
      gQTree[currentnode].uDepth = depth;
      gQTree[currentnode].uSubTreeSize = 1;
      gQTree[currentnode].uChildNode = 0;

      for(int p = gNodeId[currentnode]; p; p = gNodeEdge[p].uNextNode) {
            int &nextnode = gNodeEdge[p].uToNode;

          if(nextnode == parentnode) continue;

          gQTree[nextnode].uCost = gNodeEdge[p].uEdgeWeight;
          DepthFirstSearch(nextnode, currentnode, depth + 1);
          gQTree[currentnode].uSubTreeSize += gQTree[nextnode].uSubTreeSize;

          if(gQTree[nextnode].uSubTreeSize > maxsize) {
              maxsize = gQTree[nextnode].uSubTreeSize;
              gQTree[currentnode].uChildNode = nextnode;
          }
      }
}
  
void ConstSegTree(int curnode, int top) {

      gSegTreeID[curnode] = ++gSegmentTreeNode;
      gTopNode[curnode] = top;

      AdjustWeight(1, 1, gNoOfNodes, gSegTreeID[curnode], gQTree[curnode].uCost);

      if(gQTree[curnode].uChildNode){
          ConstSegTree(gQTree[curnode].uChildNode, top);
      }

      for(int i = gNodeId[curnode]; i; i = gNodeEdge[i].uNextNode) {
          int &tonode = gNodeEdge[i].uToNode;

          if(tonode == gQTree[curnode].uParentNode || tonode == gQTree[curnode].uChildNode) 
              continue;
          ConstSegTree(tonode, tonode);
      }
}
  
int FindMaxCost(int x, int y) {
      int ret = 0;
      while(gTopNode[x] != gTopNode[y]) {
          if(gQTree[gTopNode[x]].uDepth < gQTree[gTopNode[y]].uDepth) swap(x, y);
          ret = max(ret, Query(1, 1, gNoOfNodes, gSegTreeID[gTopNode[x]], gSegTreeID[x]));
          x = gQTree[gTopNode[x]].uParentNode;
      }
      if(gQTree[x].uDepth > gQTree[y].uDepth) swap(x, y);
      ret = max(ret, Query(1, 1, gNoOfNodes, gSegTreeID[x] + 1, gSegTreeID[y]));
      return ret;
}
  
  void Change(int edgeid, int cost) {
      int u = gNodeEdge[edgeid].uToNode, v = gNodeEdge[edgeid ^ 1].uToNode;
      if(gQTree[u].uParentNode == v) swap(u, v);
      AdjustWeight(1, 1, gNoOfNodes, gSegTreeID[v], cost);
  }
  

  
 int main() {

        int testcases; 
        int beginnode;
        int endnode;
        int weight;
        int node1, node2;

     scanf("%d", &testcases);
     for(int t = 1; t <= testcases; ++t) {

         scanf("%d", &gNoOfNodes);
         memset(gNodeId, 0, sizeof(gNodeId));
         gEdgeCount = 2;

         for(int i = 1; i < gNoOfNodes; ++i) {
            
            scanf("%d%d%d", &beginnode, &endnode, &weight);
            gEdgeId[i] = gEdgeCount;
            IncludeEdge(beginnode, endnode, weight);
        }
        memset(gSegmentTree, 0, sizeof(gSegmentTree));
        DepthFirstSearch(1, 0, 0); 
        gQTree[1].uCost = -1;
        gSegmentTreeNode = 0;
        ConstSegTree(1, 1);
        while(scanf("%s", input) && *input != 'D') {
            
            scanf("%d%d", &node1, &node2);
            if(*input == 'C') {
                Change(gEdgeId[node1], node2);
            }
            else {
                 printf("%d\n", FindMaxCost(node1, node2));
            }
         }
    }
}

