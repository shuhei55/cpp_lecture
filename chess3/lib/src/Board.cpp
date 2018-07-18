#include "Board.hpp"
#include <string>

Board::addkoma(std::weak_ptr<AbstKoma> new_koma)
{
    try {
        if ()
            std::shared_ptr<AbstKoma> shared_koma = new_koma.lock();
        koma[shared_koma->return_tate()][shared_koma->return_yoko()] = new_koma;
    } catch (string st) {
        cout << "error: " << st << endl;
    }
}
