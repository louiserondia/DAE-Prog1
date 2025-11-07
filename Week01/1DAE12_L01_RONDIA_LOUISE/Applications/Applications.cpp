// Rondia, Louise, 1DAE12

#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

int main()
{
    // RGBA 

    int red{};
    int green{};
    int blue{};
    int alpha{};

    std::cout << "RGBA in [0, 255]? ";
    std::cin >> red;
    std::cin >> green;
    std::cin >> blue;
    std::cin >> alpha;

    float fRed{ red / 255.f };
    float fGreen{ green / 255.f };
    float fBlue{ blue / 255.f };
    float fApha{ alpha / 255.f };

    std::cout << "RGBA in  [0.0f, 1.0f]:\n" 
        << fRed << std::endl 
        << fGreen << std::endl 
        << fBlue << std::endl 
        << fApha << std::endl << std::endl;

    // KM -> M & CM

    float km{};

    std::cout << "Distance in km? ";
    std::cin >> km;
    std::cout << km * 1000 << " meters, " << km * 100000 << " cm\n\n";

    // RAD -> DEG

    float rad{};

    std::cout << "Angle in radians? ";
    std::cin >> rad;
    std::cout << rad * 180 / M_PI << " degrees\n\n";

    // DEG -> RAD 

    float deg{};

    std::cout << "Angle in degrees? ";
    std::cin >> deg;
    std::cout << deg / 180 * M_PI << " radians\n\n";

    // SECONDS -> deg/s

    float s{};

    std::cout << "Seconds on one rotation? ";
    std::cin >> s;
    std::cout << 360 / s << " degrees/second\n\n";

    // SPEED & ELAPSED TIME -> METERS

    float speed{};
    float elapsedTime{};

    std::cout << "Speed (km/h)? ";
    std::cin >> speed;   
    std::cout << "Elapsed time (minutes)? ";
    std::cin >> elapsedTime;
    std::cout << speed * elapsedTime / 60 * 1000 << " meters\n\n";

    // SECONDS -> velocity of a falling object

    std::cout << "Seconds? ";
    std::cin >> s;
    std::cout << "Velocity " << s * 9.8 << " m/sec\n\n";

    // RADIUS -> CIRCUMFERENCE AND AREA

    float radius{};

    std::cout << "Radius of circle? ";
    std::cin >> radius;
    std::cout << "Circumference: " << radius * 2 * M_PI << "\n";
    std::cout << "Area: " << (radius * radius) * M_PI << "\n\n";

    // RECTANGLE WIDTH + HEIGHT -> CIRCUMFERENCE AND AREA

    float width{};
    float height{};

    std::cout << "Width and height? ";
    std::cin >> width;
    std::cin >> height;
    std::cout << "Circumference: " << 2 * width + 2 * height << "\n";
    std::cout << "Area: " << width * height << "\n\n";

    // TRIANGLE BASE + HEIGHT -> AREA

    float base{};

    std::cout << "Base and height? ";
    std::cin >> base;
    std::cin >> height;
    std::cout << "Area: " << (base * height) / 2;
}
