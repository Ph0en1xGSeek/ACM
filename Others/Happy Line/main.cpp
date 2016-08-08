//不是最后一个取的一定要想办法把其中一堆取光
//

#include <stdio.h>
#include <iostream>


using namespace std;
int n, k, odd, even;

int main()
{
    scanf("%d%d", &n, &k);
    for( int i = 1, x; i <= n; ++i ) {
        scanf("%d", &x);
        odd += x & 1;
        even += !( x & 1 );
    }
    int tot = odd & 1;///一个都不拆的情况，初始化
    int t = n - k;
    if( t > 0 )
    {
        if( t & 1 )///S最后一个取
        {
            tot = 0;///假设S不能赢
            if( ( min( odd, even ) > t / 2 ) || ( odd > even && k & 1 ) )   tot = 1;
            ///S可以做到取不完（取和对方不一样的） 或 剩下奇数且为奇数个 （如果只剩偶数 S必败）
        }
        else///D最后一个取
        {
            tot = 1;
            if( ( min( odd, even ) > (t+1) / 2 ) || ( odd > even && !( k & 1 ) ) || ( even > odd ) )   tot = 0;
            ///D可以做到取不完 或 剩下奇数且个数为偶数个 或 只剩偶数
        }
    }
    puts( tot ? "Stannis" : "Daenerys"  );
}
