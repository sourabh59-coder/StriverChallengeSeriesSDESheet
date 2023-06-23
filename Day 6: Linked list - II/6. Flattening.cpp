Node* mergeTwoLists(Node* a, Node* b){
         
         Node* temp= new Node(0);
         Node* res= temp;
         
         while(a!=NULL && b!=NULL){
             if(a->data < b->data){
                 temp->bottom= a;
                 temp= temp->bottom;
                 a= a->bottom;
             }
             
             else{
                 temp->bottom= b;
                 temp= temp->bottom;
                 b= b->bottom;
             }
         }
         
         if(a!=NULL){
             
             temp->bottom= a;
         }
         
         else{
             temp->bottom= b;
         }
         
         return res->bottom;
         
    }
    
// Now we perform the recursive operations.
    
Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL){
       return root;
   }
  
  // recursion for the list on the right.
  
   root->next= flatten(root->next);
   
   // Now we merge the list.
   
   root= mergeTwoLists(root, root->next);
   
   return root;
   
}
