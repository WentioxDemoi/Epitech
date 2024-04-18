#ifndef _ICOLLIDABLE_HPP_
#define _ICOLLIDABLE_HPP_

class ICollidable
{
    public:
        virtual bool IsCollide(ICollidable &other) = 0;
        virtual const ICollidable &getCollidable() const = 0;
        virtual Vector3 &getCollidable_pos() = 0;
    private:
};


#endif /* _ICOLLIDABLE_HPP_ */
