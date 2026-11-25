class StockSpanner {
    int currIdx;
    stack<pair<int, int>> prevStock;
public:
    StockSpanner() {
        currIdx = 1;
        prevStock.push({INT_MAX, 0});
    }
    /*
        stack = [[100, 0]]
        currIdx = 6
        ans = 1
        seq = [[], [100], [80], [60], [70], [60], [75], [85]]
    */
    int next(int price) {
        
        int ans = 1;

        while(not prevStock.empty()){
            ans = currIdx - prevStock.top().second;
            if(prevStock.top().first > price)
                break;
            prevStock.pop();
        }

        prevStock.push({price, currIdx++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */