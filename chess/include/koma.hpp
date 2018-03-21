#pragma once
class Abstkoma
{
public:
    bool check_alive()
    {
        return !(m_tate == 0 || m_yoko == 0);
    }

    virtual void change_position(uint8_t new_tate, uint8_t new_yoko) const = 0;

    void removed()
    {
        m_tate = 0;
        m_yoko = 0;
    }

private:
    uint8_t m_tate m_yoko;
};
