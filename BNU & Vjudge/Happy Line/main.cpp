//�������һ��ȡ��һ��Ҫ��취������һ��ȡ��
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
    int tot = odd & 1;///һ����������������ʼ��
    int t = n - k;
    if( t > 0 )
    {
        if( t & 1 )///S���һ��ȡ
        {
            tot = 0;///����S����Ӯ
            if( ( min( odd, even ) > t / 2 ) || ( odd > even && k & 1 ) )   tot = 1;
            ///S��������ȡ���꣨ȡ�ͶԷ���һ���ģ� �� ʣ��������Ϊ������ �����ֻʣż�� S�ذܣ�
        }
        else///D���һ��ȡ
        {
            tot = 1;
            if( ( min( odd, even ) > (t+1) / 2 ) || ( odd > even && !( k & 1 ) ) || ( even > odd ) )   tot = 0;
            ///D��������ȡ���� �� ʣ�������Ҹ���Ϊż���� �� ֻʣż��
        }
    }
    puts( tot ? "Stannis" : "Daenerys"  );
}
