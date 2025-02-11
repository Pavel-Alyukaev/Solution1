std::vector<Point> readPointsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Point> points;

    if (!file.is_open()) {
        std::cerr << "Mistake: couldn't open the file " << filename << std::endl;
        return points;
    }

    double x, y, z;
    while (file >> x >> y >> z) {
        points.emplace_back(x, y, z);
    }

    file.close();
    return points;
}

int main(int argc, char* argv[])
{
    if (argc != 5) {
        std::cerr << "Using: " << argv[0] << " <path_to_file> <x> <y> <z>" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];
    double x = std::stod(argv[2]);
    double y = std::stod(argv[3]);
    double z = std::stod(argv[4]);

    const Point O{x, y, z};

    std::vector<Point> points = readPointsFromFile(filePath);


    std::map<int, Point> closestPoints;
    double minDistance = std::numeric_limits<double>::max();
    const double epsilon = std::numeric_limits<double>::epsilon();

    for (size_t i = 1; i < points.size(); ++i) {
        Tmp t(points[i - 1], points[i], O);
        auto [distance, point] = t.Calculate();
        if (minDistance - distance > epsilon) {
            minDistance = distance;
            closestPoints.clear();
            closestPoints.emplace(i, point);
        } else if (std::abs(minDistance - distance) < epsilon) {
            closestPoints.emplace(i, point);
        }
    }

    for (const auto& [index, point] : closestPoints) {
        std::cout << "segment " << index << " point " << point.toString() << std::endl;
    }

    return 0;
}