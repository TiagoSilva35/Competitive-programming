#include <bits/stdc++.h>

using namespace std;

typedef double T;
// Define EPS as 1e-10
const T EPS = 1e-10;

struct Point2D
{
    T x, y;
    Point2D(T x = 0, T y = 0) : x(x), y(y) {}
    // Simple operations
    Point2D operator+(const Point2D &p) const { return Point2D(x + p.x, y + p.y); }
    Point2D operator-(const Point2D &p) const { return Point2D(x - p.x, y - p.y); }
    Point2D operator*(T k) const { return Point2D(x * k, y * k); }
    Point2D operator/(T k) const { return Point2D(x / k, y / k); }
    T operator*(const Point2D &p) const { return x * p.x + y * p.y; }
    T operator^(const Point2D &p) const { return x * p.y - y * p.x; }
    // Complex operations
    T norm() const { return x * x + y * y; } // Norm of the vector
    T abs() const { return sqrt(norm()); }   // Length of the vector
    // Compare operations
    bool operator<(const Point2D &p) const
    {
        return x != p.x ? x < p.x : y < p.y;
    }
    bool operator==(const Point2D &p) const
    {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
    // Other operations
    std::string to_string() const
    {
        std::stringstream ss;
        ss << "(" << x << ", " << y << ")";
        return ss.str();
    }
};

// ----- Operations between POINTS ----- //
T dot(Point2D a, Point2D b) { return a.x * b.x + a.y * b.y; }                  // Dot product
T cross(Point2D a, Point2D b) { return a.x * b.y - a.y * b.x; }                // Cross product
T proj(Point2D a, Point2D b) { return dot(a, b) / b.abs(); }                   // Projection of a on b
T angle(Point2D a, Point2D b) { return acos(dot(a, b) / a.abs() / b.abs()); }  // Angle between a and b
bool is_parallel(Point2D a, Point2D b) { return fabs(cross(a, b)) < EPS; }     // Check if vectors are parallel
bool is_perpendicular(Point2D a, Point2D b) { return fabs(dot(a, b)) < EPS; }  // Check if vectors are perpendicular
T orientation(Point2D a, Point2D b, Point2D c) { return cross(b - a, c - a); } // Orientation of three points: > 0 if ccw, < 0 if cw, = 0 if collinear

// Verify if P lies in the angle ABC
bool in_angle(Point2D a, Point2D b, Point2D c, Point2D p)
{
    return orientation(a, b, p) >= 0 && orientation(b, c, p) >= 0 && orientation(c, a, p) >= 0;
}

struct Line2D
{
    Point2D v;
    T c; // ax + by + c = 0
    Line2D(Point2D v = Point2D(1, 0), T c = 0) : v(v), c(c) {}
    Line2D(Point2D p, Point2D q) : v(q - p), c(cross(v, p)) {}
    // Complex operations
    T side(Point2D p) const { return cross(v, p) - c; }                           // Side of the line where p is: > 0 if left, < 0 if right, = 0 if on the line
    double dist(Point2D p) const { return fabs(cross(v, p) - c) / v.abs(); }      // Distance from point to line
    bool cmp_proj(Point2D p, Point2D q) const { return proj(v, p) < proj(v, q); } // Compare projections of p and q on the line: True if p comes before q
    Line2D translate(Point2D t) const { return Line2D(v, c + cross(v, t)); }      // Translate the line by vector t
    // Other operations
    std::string to_string() const
    {
        std::stringstream ss;
        ss << v.to_string() << " " << c;
        return ss.str();
    }
};

// ----- Operations between LINES ----- //
bool parallel(Line2D l1, Line2D l2) { return is_parallel(l1.v, l2.v); }                 // Check if lines are parallel
bool same(Line2D l1, Line2D l2) { return parallel(l1, l2) && fabs(l1.c - l2.c) < EPS; } // Check if lines are the same
bool intersect(Line2D l1, Line2D l2, Point2D &p)
{ // Check if lines intersect. If so, p is the intersection point
    T d = cross(l1.v, l2.v);
    if (fabs(d) < EPS)
        return false;
    p = (l2.v * l1.c - l1.v * l2.c) / d;
    return true;
}

// ----- Operations between POINTS and LINES ----- //
bool on_line(Line2D l, Point2D p) { return fabs(l.side(p)) < EPS; } // Check if point is on line

// ----- Operations on Polygon ----- //
// Verify if a polygon is convex
bool is_convex(const std::vector<Point2D> &polygon)
{
    int n = polygon.size();
    bool has_pos = false, has_neg = false;
    for (int i = 0; i < n; i++)
    {
        int o = orientation(polygon[i], polygon[(i + 1) % n], polygon[(i + 2) % n]);
        if (o > 0)
            has_pos = true;
        if (o < 0)
            has_neg = true;
    }
    return !(has_pos && has_neg);
}
// Compute the area of a polygon
T area(const std::vector<Point2D> &polygon)
{
    T result = 0.0;
    for (int i = 0; i < (int)polygon.size(); i++)
    {
        int j = (i + 1) % polygon.size();
        result += cross(polygon[i], polygon[j]);
    }
    return fabs(result) / 2.0;
}
// Compute the are of a triangle
T area(Point2D a, Point2D b, Point2D c) { return fabs(cross(b - a, c - a)) / 2.0; }
// Verify if a point is inside a polygon
bool in_polygon(const std::vector<Point2D> &polygon, Point2D p)
{
    int n = polygon.size();
    T sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (on_line(Line2D(polygon[i], polygon[(i + 1) % n]), p))
            return true;
        sum += angle(polygon[i] - p, polygon[(i + 1) % n] - p);
    }
    return fabs(fabs(sum) - 2 * M_PI) < EPS;
}

// ----- Operations on Segments ----- //

bool on_segment(Point2D a, Point2D b, Point2D p)
{
    return orientation(a, b, p) == 0 && dot(p - a, p - b) <= 0;
}

bool seg_intersect(Point2D a, Point2D b, Point2D c, Point2D d, Point2D &p)
{
    T d1 = cross(d - c, a - c);
    T d2 = cross(d - c, b - c);
    if (d1 * d2 > EPS)
        return false;
    T d3 = cross(b - a, c - a);
    T d4 = cross(b - a, d - a);
    if (d3 * d4 > EPS)
        return false;
    if (d1 * d2 < -EPS && d3 * d4 < -EPS)
    {
        p = a + (b - a) * d3 / (d3 - d4);
        return true;
    }
    // Special case: one of the endpoints is on the other segment
    if (fabs(d1) < EPS && on_segment(c, d, a))
    {
        p = a;
        return true;
    }
    if (fabs(d2) < EPS && on_segment(c, d, b))
    {
        p = b;
        return true;
    }
    if (fabs(d3) < EPS && on_segment(a, b, c))
    {
        p = c;
        return true;
    }
    if (fabs(d4) < EPS && on_segment(a, b, d))
    {
        p = d;
        return true;
    }
    return false;
}

bool in_triangle(Point2D a, Point2D b, Point2D c, Point2D p)
{
    int o1 = orientation(a, b, p);
    int o2 = orientation(b, c, p);
    int o3 = orientation(c, a, p);

    return (o1 >= 0 && o2 >= 0 && o3 >= 0) || (o1 <= 0 && o2 <= 0 && o3 <= 0);
}


int countEars(const vector<Point2D> &polygon) {
    int n = (int)polygon.size();
    int ANS = 0;
    bool isEar = 0;
    for (int i = 1; i < n-1; i++) {
        Point2D prev = polygon[i-1];
        Point2D curr = polygon[i];
        Point2D next = polygon[i+1];

        bool isConcave = orientation(prev, curr, next) < 0;

        isEar = isConcave;
        for (int j = 0; j < n-1; j++) {
            if (j != i && j != (i + 1) && j != (i - 1)) {
                if (in_triangle(prev, curr, next, polygon[j])) {
                    isEar = false;
                    break;
                }
            }
        }
        if (isEar) {
            ANS++;
        }
    }
    bool isConcave = orientation(polygon[n-2], polygon[n-1], polygon[0]) < 0;
    isEar = isConcave;
    for (int j = 0; j < n-1 ; j++){
        if (j != n-2 && j != n-1 && j != 0){
            if ((in_triangle(polygon[n-2], polygon[n-1], polygon[0], polygon[j]))) {
                isEar = false;
                break;
            }
        }
    }
    if (isEar) {
        ANS++;
    }
    isConcave = orientation(polygon[n-1], polygon[0], polygon[1]) < 0;
    isEar = isConcave;
    for (int j = 0; j < n-1 ; j++){
        if (j != 0 && j != n-1 && j != 1){
            if ((in_triangle(polygon[n-1], polygon[0], polygon[1], polygon[j]))) {
                isEar = false;
                break;
            }
        }
    }
    if (isEar) {
        ANS++;
    }

    return ANS;
}



int main() {
    int n;
    cin >> n;

    vector<Point2D> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    int earCount = countEars(polygon);
    cout << earCount << endl;

    return 0;
}
