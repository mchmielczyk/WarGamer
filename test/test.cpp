#include "../player.h"
#include <gtest/gtest.h>
#include <fstream>
#include <vector>
#include <string>
#include "../main.cpp"  

TEST(MapMakerTest, FileNotFound) {
    std::string filename = "nonexistent_file.txt";
    std::vector<std::vector<Point>> result = MapMaker(filename);

    // Sprawdź, czy funkcja zwraca pustą mapę
    EXPECT_TRUE(result.empty());
}

TEST(MapMakerTest, ValidFile) {
    std::string filename = "valid_file.txt";
    std::ofstream file(filename);
    file << "123\n";
    file << "456\n";
    file << "789\n";
    file.close();

    std::vector<std::vector<Point>> expected_map = {
        {{0, 0, 1}, {0, 1, 2}, {0, 2, 3}},
        {{1, 0, 4}, {1, 1, 5}, {1, 2, 6}},
        {{2, 0, 7}, {2, 1, 8}, {2, 2, 9}}
    };

    std::vector<std::vector<Point>> result = MapMaker(filename);

    // Sprawdź, czy funkcja zwraca oczekiwaną mapę
    EXPECT_EQ(result, expected_map);
}
TEST(StatusReaderTest, FileNotFound) {
    std::string filename = "nonexistent_file.txt";
    std::vector<Unit*> PUnits;
    std::vector<Unit*> EUnits;
    StatusReader(filename, PUnits, EUnits);

    // Sprawdź, czy funkcja nie zmienia wektorów jednostek
    EXPECT_TRUE(PUnits.empty());
    EXPECT_TRUE(EUnits.empty());
}
TEST(StatusReaderTest, ValidFile) {
    std::string filename = "valid_file.txt";
    std::ofstream file(filename);
    file << "1 2 3 4 5\n";
    file << "6 7 8 9 10\n";
    file.close();

    std::vector<Unit*> PUnits;
    std::vector<Unit*> EUnits;
    StatusReader(filename, PUnits, EUnits);

    // Sprawdź, czy funkcja zmienia wektory jednostek
    EXPECT_EQ(PUnits.size(), 1);
    EXPECT_EQ(EUnits.size(), 1);
}

