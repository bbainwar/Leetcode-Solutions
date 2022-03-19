class FreqStack {
public:
  priority_queue<vector<int>> pq; //make a max heap of 3 items per element.
    unordered_map<int, int> m; //create a frequency map for 
    int count=0; //iterator.
    public:
    FreqStack(){ //constructor which we never use.
    }
    void push(int x){ //to push element x in the stack.
        ++m[x]; //frequency map bana ek waha frequency update krte ja.
        pq.push({m[x],count++,x}); //heap mein frequency, count aur data dal
    }
    int pop(){
        auto maxx = pq.top(); //sbse zyada aaya hua elemenet hum maxx me store karayega
        pq.pop(); //max element ko pop krde, we no longer need it.
        --m[maxx[2]]; //kyunki pop kiya to element ki frequency kam karni hogi.
        return maxx[2]; //ab wo element return krdo
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */