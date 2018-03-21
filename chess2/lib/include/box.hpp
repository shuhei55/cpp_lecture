#pragma once
//#include ""

class Box
{
public:
    explicit Box(const std::array<std::array<std::shared_ptr<AbstKoma>, 8>, 8>& koma)
    {
        m_koma = koma;
    }

    uint8_t check_koma(uint8_t tate, uint8_t yoko) const
    {
        return m_koma.at(tate).at(yoko)->returnID();
    }

private:
    const std::array<std::array<std::shared_ptr<AbstKoma>, 8>, 8> m_koma;
};
