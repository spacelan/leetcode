/** \link https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
 * \comments 妈蛋，一个多么蛋疼的动规题。之前遇到之后想了半天没有想出算法就放在一边了，今天再拿出来做，从前往后推，算法没有问，但是直接爆栈了。那测试数据一看，我靠，k和prices数组长度都好高。后来就再研究算法，又悄悄看了一下论坛里的做法，发现k只和本次和上一次有关，那么就profit第一维就直接减小到2了。好不容易把空间复杂度降下来，时间有特么超了，还是那个k，超大。但是根据本题的意思，当2*k大于prices数组长度时，那么每个可获利交易均可以执行。所以有另外写了一个处理过程，配合之前提取出来的只有峰和谷的子prices数组，很容易就完成了。虽然最后AC，但时间复杂度还是很高，O(k*n^2)，论坛里有更好的算法，之后研究一下。总之，这个题做得十分拙计，各种问题都遇到了，还是体现出自己基本功不够，思路也要更广，比如动规，反推不行试试正推啊！！
 */
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if(prices.size() == 0) return 0;
        vector<int> p;
        p.push_back(prices[0]);
        for(int i=1;i<prices.size();i++){
            int j = i;
            while(prices[i] == prices[j] && j<prices.size()) j++;
            if(j>=prices.size()) p.push_back(prices[i]);
            else if(prices[i]<prices[i-1] && prices[i]<prices[j]) p.push_back(prices[i]);
            else if(prices[i]>prices[i-1] && prices[i]>prices[j]) p.push_back(prices[i]);
        }
        prices = p;

        if(k >= (prices.size()+1) / 2){
            int profit = 0;
            if(prices[0]<prices[1]) profit -= prices[0];
            for(int i=1;i<prices.size()-1;i++){
                if(prices[i]<prices[i-1] && prices[i]<prices[i+1]) profit -= prices[i];
                else if(prices[i]>prices[i-1] && prices[i]>prices[i+1]) profit += prices[i];
            }
            if(prices[prices.size()-1]>prices[prices.size()-2]) profit += prices[prices.size()-1];
            return profit;
        }


        k = (prices.size()+1)/2<k?(prices.size()+1)/2:k;
        int profit[2][prices.size()];
        memset(profit,0,2*prices.size()*sizeof(int));
        for(int t=1;t<=k;t++){
            for(int d=1;d<prices.size();d++){
                profit[t%2][d] = profit[t%2][d-1];
                for(int i=0;i<d;i++){
                    if(profit[(t-1)%2][i]-prices[i]+prices[d]>profit[t%2][d]){
                        profit[t%2][d] = profit[(t-1)%2][i] - prices[i] + prices[d];
                    }
                }
            }
        }
 /*       for(int d=1;d<prices.size();d++){
            for(int t=1;t<=k;t++){
                profit[t][d] = profit[t][d-1];
                for(int i=0;i<d;i++){
                    if(profit[t-1][i]-prices[i]+prices[d]>profit[t][d]){
                        profit[t][d] = profit[t-1][i] - prices[i] + prices[d];
                    }
                }
            }
        }*/
        return profit[k%2][prices.size()-1];
    }
};
