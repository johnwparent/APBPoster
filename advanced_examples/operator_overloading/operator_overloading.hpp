#include <string>

class Vector2 {
public:
    Vector2(float x, float y) : x(x), y(y) {  }
    Vector2(const Vector2 &v) : x(v.x), y(v.y) {  }
    Vector2(Vector2 &&v) : x(v.x), y(v.y) {  }
    Vector2 &operator=(const Vector2 &v) { x = v.x; y = v.y;  return *this; }
    Vector2 &operator=(Vector2 &&v) { x = v.x; y = v.y; v.x = v.y = 0;  return *this; }
    ~Vector2() {  }

    std::string toString() const { return "[" + std::to_string(x) + ", " + std::to_string(y) + "]"; }

    Vector2 operator-() const { return Vector2(-x, -y); }
    Vector2 operator+(const Vector2 &v) const { return Vector2(x + v.x, y + v.y); }
    Vector2 operator-(const Vector2 &v) const { return Vector2(x - v.x, y - v.y); }
    Vector2 operator-(float value) const { return Vector2(x - value, y - value); }
    Vector2 operator+(float value) const { return Vector2(x + value, y + value); }
    Vector2 operator*(float value) const { return Vector2(x * value, y * value); }
    Vector2 operator/(float value) const { return Vector2(x / value, y / value); }
    Vector2 operator*(const Vector2 &v) const { return Vector2(x * v.x, y * v.y); }
    Vector2 operator/(const Vector2 &v) const { return Vector2(x / v.x, y / v.y); }
    Vector2& operator+=(const Vector2 &v) { x += v.x; y += v.y; return *this; }
    Vector2& operator-=(const Vector2 &v) { x -= v.x; y -= v.y; return *this; }
    Vector2& operator*=(float v) { x *= v; y *= v; return *this; }
    Vector2& operator/=(float v) { x /= v; y /= v; return *this; }
    Vector2& operator*=(const Vector2 &v) { x *= v.x; y *= v.y; return *this; }
    Vector2& operator/=(const Vector2 &v) { x /= v.x; y /= v.y; return *this; }

    friend Vector2 operator+(float f, const Vector2 &v) { return Vector2(f + v.x, f + v.y); }
    friend Vector2 operator-(float f, const Vector2 &v) { return Vector2(f - v.x, f - v.y); }
    friend Vector2 operator*(float f, const Vector2 &v) { return Vector2(f * v.x, f * v.y); }
    friend Vector2 operator/(float f, const Vector2 &v) { return Vector2(f / v.x, f / v.y); }

    bool operator==(const Vector2 &v) const {
        return x == v.x && y == v.y;
    }
    bool operator!=(const Vector2 &v) const {
        return x != v.x || y != v.y;
    }
private:
    float x, y;
};