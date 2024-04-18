#pragma once

namespace component
{
    class Parallax
    {
        public:
            Parallax(float p) {_parallax = p;};
            ~Parallax() {};
            float get_parallax() const {return _parallax;};
        private:
            float _parallax;
    };
};