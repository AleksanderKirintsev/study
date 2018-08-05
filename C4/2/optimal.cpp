#include <iostream>

using namespace std;
/*
m1, m2 - 2 ����������� �������� ������� 2 ��� ������ 201, ���� �� ������� (������ �1 - ��� ������ �������, � �2 - �������)
m3, m4 - 2 ����������� �������� �� ������� 2 ��� ������ 201, ���� �� �������  (������ �3 - ��� ������ �������, � �4 - �������)

*/
int main()
{
    int n, a;
    int m1 = 201, m2 = 201; // 2 ����������� �������� ������� 2 ��� ������ 201, ���� �� ������� (������ �1 - ��� ������ �������, � �2 - �������)
    int m3 = 201, m4 = 201; // 2 ����������� �������� �� ������� 2 ��� ������ 201, ���� �� �������  (������ �3 - ��� ������ �������, � �4 - �������)

    cin >> n;

    for ( int i = 0; i < n; i++ )
    {
        cin >> a;

        if ( a % 2 == 0 && m1 > a)
        {
            m2 = m1;
            m1 = a;
        }
        else if ( a % 2 == 0 && m1 <= a && m2 > a)
            m2 = a;

        if ( a % 2 != 0 && m3 > a)
        {
            m4 = m3;
            m3 = a;
        }
        else if ( a % 2 != 0 && m3 <= a && m4 > a)
            m4 = a;
    }

    if ( ( m1 == 201 || m2 == 201 ) && ( m3 == 201 || m4 == 201 ) )
        cout << min ( min ( m1 + m3, m1 + m4 ), min ( m2 + m3, m2 + m4 ) );
    else
        cout << min ( m1 + m2, m3 + m4 );

return 0;
}
