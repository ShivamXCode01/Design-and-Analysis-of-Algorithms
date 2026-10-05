#include <iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node *right ;
        
    node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;

    }
};

node* buildTree(node*root){
    cout << " Enter the Data  : ";
    int data ;
    cin >> data ;

    root = new node(data);

    if (data == -1){
        return NULL;
    }
    root = new node(data);
    
    cout << " for left node  \n";
    root -> left = buildTree(root->left);
    
    cout << "for right node  \n" ;
    root -> right = buildTree(root -> right );
    
    

    return root ;
}

void BFSTraversal(node*root){

    if (root == NULL)
        return;

    queue<node*>q;
    q.push(root);

    while (!q.empty()){
        node*temp = q.front();
        q.pop();

        cout << temp -> data  << "  ";

        if (temp -> left){
            q.push (temp -> left);
        }
        if (temp -> right){
            q.push(temp -> right);
            
        }
    }
}
void DFSTraversal(int start, vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    stack<int> s;

    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    s.push(neighbour);
                }
            }
        }
    }
}


int main (){

    node * root = NULL;
    root = buildTree(root);

    BFSTraversal(root);
    cout << endl;
    DFSTraversal(root);

    return 0 ; 
}
