#include <cstdio>
#include <iostream>

#define MAXCHAR 32768
#define MAXNODE 65536

using namespace std;

char    brackets[MAXCHAR];
int     Tree[MAXNODE];
int     Tree2[MAXNODE];

inline void UpdateTree (int Node, int a, int b, int index) {

	if(a==b) {

		Tree[Node] = Tree2 [Node] = -Tree[Node];
		return;
	}

	int mid = (a+b)/2;

	if(index <= mid)
        UpdateTree (2*Node, a, mid, index);

	else
        UpdateTree (2*Node+1, mid+1, b, index);

	Tree[Node] = Tree[2*Node] + Tree[2*Node+1];
    Tree2 [Node] = min (Tree2 [2*Node], Tree [2*Node] + Tree2 [2*Node+1]); 
}

inline void InitializeTree (int Node, int a, int b) {

    if(a==b) {

        int val = brackets[a] == '(' ? 1 : -1;
		Tree[Node] = Tree2[Node] = val;
        return;
	}

	int mid = (a+b)/2;

	InitializeTree (2*Node, a, mid);
	InitializeTree (2*Node+1, mid+1, b);

    Tree [Node] = Tree[2*Node] + Tree[2*Node+1];
    Tree2 [Node] = min (Tree2 [2*Node], Tree [2*Node] + Tree2 [2*Node+1]); 
}

int main() {
	int length, query, index, testcase = 1;

    while(testcase <= 10) {

        scanf("%d", &length);
		scanf("%s", brackets);
		scanf("%d", &query);

		InitializeTree (1, 0, length-1);

		printf("Test %d:\n", testcase++);

        for(int  i=0; i<query; i++) {

			scanf("%d", &index);

			if(!index) {

				if(Tree[1] == 0 && Tree2 [1] == 0)
                    printf("YES\n");
				else
                    printf("NO\n");
			}
			else
                UpdateTree (1, 0, length-1, index-1);
		}
	}
	return 0;
}
