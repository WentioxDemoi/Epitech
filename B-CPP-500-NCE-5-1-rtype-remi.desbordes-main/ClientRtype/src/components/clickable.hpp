#pragma once

namespace component
{
    class Clickable
    {
        public:
            Clickable(std::string button_name) {_button_name = button_name;};
            ~Clickable() {};
            std::string get_button_name(void) const {return _button_name;};
        private:
            std::string _button_name;
    };
};