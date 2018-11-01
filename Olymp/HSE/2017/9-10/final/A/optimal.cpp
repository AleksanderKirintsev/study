#include <iostream>
using namespace std;

int main()
{
    long long int dh,dm,hw,mw,ah,am,tz1,tz2,days = 0; // d - departure, w - in way, a arrive, tz- time zone
    cin >> dh >> dm;
    cin >> hw >> mw;
    cin >> tz1 >> tz2;

    days +=((dh * 3600 + dm * 60) + (hw * 3600 + mw * 60) + (tz2 - tz1) * 3600) / 86400; // время отправление + время в пути + разность часовых поясов
    ah = (dh + hw) + (tz2 - tz1) + (dm + mw) / 60 - days * 24;
    am = (mw + dm) % 60;

    cout << ah << " " << am << " " << days;
    return 0;
}
