class Solution {

private:
    struct Node{
        Node* links[2];
    };

    class Trie{
        private:
            Node* root;
        
        public:
            Trie(){
                root=new Node();

            }

            void insert(int num)
            {
                Node* node= root;
                for(int i=31;i>=0;i--)
                {
                    int index= (num>>i) &1;
                if(node->links[index]==NULL)
                {
                    node->links[index]=new Node();

                }
                    node=node->links[index];
                }
            }

            int getMax(int num)
            {
                Node* node=root;
                int maxnum=0;
                for(int i=31;i>=0;i--)
                {
                    int bin =(num>>i)&1;
                    int index=!bin;
                    if(node->links[index]!=NULL)
                    {
                        maxnum= maxnum|(1<<i);
                        node=node->links[index];
                    }
                    else{
                        node=node->links[bin];
                    }

                }
                return maxnum;
            }
    };
    
public:
    int findMaximumXOR(vector<int>& nums) {
        int  maxi=0;
        
        Trie trie;
        
        for(auto it:nums)
        
        trie.insert(it);
        
        for(auto it:nums) maxi=max(maxi,trie.getMax(it));
        
        return maxi;
    }
};