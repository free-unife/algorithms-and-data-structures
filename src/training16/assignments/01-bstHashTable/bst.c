void initBST( bst root ){
  *root = NULL;
}

boolean isBSTempty( bst root ){
  return *root == NULL;
}

pointerToNode newNode( char *key, char *value ){
  pointerToNode nodeAddress;

  nodeAddress->key = key;
  nodeAddress->value = value;
  nodeAddress->left = NULL;
  nodeAddress->right = NULL;
  nodeAddress->parent = NULL;

  return nodeAddress;
}

boolean lessThan( char *key1, char *key2 )
{
    if ( atoi( key1 ) < atoi( key2 ) ) {
        return true;
    } else {
        return false;
    }
}

boolean greaterThan( char *key1, char *key2 )
{
    if ( atoi( key1 ) > atoi( key2 ) ) {
        return true;
    } else {
        return false;
    }
}

pointerToNode insert(char *key, char *value, bst root){

  if( isBSTempty( root ) ){
    return newNode( key, value );
  }
  else if( lessThan( key, root->key ) ) {
    if( isBSTempty(root->left) ){
      node = newNode( key, value );
      
    }
    insert( key, value, root->left );
  }
  else{
    insert( key, value, root->right );
  }

}


/*
pointerToNode search(char *key, bst root);
boolean delete(char *key, bst root);
boolean isBST(bst root);
*/
