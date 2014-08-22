#include "PlayerAttributes.hpp"
#include "lumina/lumina.hpp" // for slog

using namespace std;

PlayerAttributes::PlayerAttributes(int hearts)
    : MAX_HEARTS(hearts)
    , m_hearts(hearts)
    , m_timer(chrono::system_clock::now())
{


}

int PlayerAttributes::getHearts()
{
    auto now = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>( now - m_timer ).count();
    if ( duration%(60*2) == 0 ) { // update heart every 2 minutes
       updateHeartsBy( 1 );
       lumina::slog("update heart +1 ...");
    }
    return m_hearts;
}

/////////////////////////////////////END OF FILE//////////////////////////////////
