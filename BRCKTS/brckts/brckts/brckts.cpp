#include <cstdio>
#include <iostream>

#define NMAX 32768
#define TMAX 65536

using namespace std;

char    seq[NMAX];
int     Tree[TMAX];
int     Tree2[TMAX];

void UpdateTree (int Node, int a, int b, int index) {

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

void InitializeTree (int Node, int a, int b) {

    if(a==b) {

        int val = seq[a] == '(' ? 1 : -1;
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
	int len, q, i, idx, test = 1;

    while(scanf("%d", &len)==1) {

		scanf("%s", seq);

		InitializeTree (1, 0, len-1);

		printf("Test %d:\n", test++);
		scanf("%d", &q);

        for(i=0; i<q; i++) {

			scanf("%d", &idx);

			if(!idx) {

				if(Tree[1] == 0 && Tree2 [1] == 0)
                    printf("YES\n");
				else
                    printf("NO\n");
			}
			else
                UpdateTree (1, 0, len-1, idx-1);
		}
	}
	return 0;
}
