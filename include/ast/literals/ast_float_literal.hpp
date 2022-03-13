class float_literal : public node
{
private:
    float value;
public:
    float_literal(float val)
    {
        value = val;
    }
};