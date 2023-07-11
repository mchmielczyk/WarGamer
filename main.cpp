#include "player.h" // Dołączenie pliku nagłówkowego "player.h", który zawiera definicje jednostek

std::vector<std::vector<Point>> MapMaker(const std::string& filename); // Deklaracja funkcji MapMaker do tworzenia mapy

int TypePicker(char c); // Deklaracja funkcji TypePicker do wyboru typu jednostki na podstawie znaku

void StatusReader(const std::string& filename, std::vector<Unit*>& _PUnits, std::vector<Unit*>& _EUnits); // Deklaracja funkcji StatusReader do odczytu stanu jednostek

int main(int argc, char* argv[])
{
    //argv[0]=player argv[1]=mapa argv[2]=status argv[3]=rozkazy argv[4]=limit czasowy

    if (argc < 4)
    {
        std::cerr << "Niewystarczajaca liczba argumentow" << "\n";
        exit(EXIT_FAILURE);
    }

    std::ifstream fin;

    for (int file = 1; file < argc - 1; file++)
    {
        fin.open(argv[file]);

        if (!fin.is_open())
        {
            std::cerr << "Blad przy otwarciu pliku: " << argv[file] << '\n';
            fin.clear();
            continue;
        }

        fin.clear();
        fin.close();
    }

    /////////////////////////////////////////
    int limitCzasowy = 5;

    if (argc > 4)
        limitCzasowy = std::atoi(argv[4]);

    /////////////////////////////////////////
    std::vector<std::vector<Point>> Map = MapMaker(argv[1]); // Wywołanie funkcji MapMaker do utworzenia mapy

    /////////////////////////////////////////
    int MapSizeX = Map.size();
    int MapSizeY = Map[0].size();

    /////////////////////////////////////////
    // Wyświetlanie mapy
    /////////////////////////////////////////
    for (const auto& row : Map) {
        for (const auto& point : row) {
            std::cout << point.type << " ";
        }
        std::cout << std::endl;
    }

    /////////////////////////////////////////
    std::cout << "Wsystko git" << "\n";

    /////////////////////////////////////////
    // Rozkazy.txt
    /////////////////////////////////////////
    std::vector<Unit*> PUnits; // Wektor wskaźników na jednostki gracza
    std::vector<Unit*> EUnits; // Wektor wskaźników na jednostki przeciwnika

    /////////////////////////////////////////
    enum UnitsPicker // Definicja enumeracji UnitsPicker
    {
        K, S, A, P, R, C, W, B
    };

    return 0;
}

// Definicja funkcji MapMaker do tworzenia mapy na podstawie pliku
std::vector<std::vector<Point>> MapMaker(const std::string& filename)
{
    std::vector<std::vector<Point>> map;
    std::ifstream file(filename);

    if (file.is_open())
    {
        std::string line;
        int i = 0;

        while (getline(file, line))
        {
            std::vector<Point> row;

            for (char c : line)
            {
                int j = 0;
                row.push_back({ i, j, c - '0' });
                j++;
            }

            map.push_back(row);
            i++;
        }

        file.close();
    }
    else
    {
        std::cerr << "Blad przy otwarciu pliku: " << filename << std::endl;
    }

    return map;
}

// Definicja funkcji StatusReader do odczytu stanu jednostek na podstawie pliku
void StatusReader(const std::string& filename, std::vector<Unit*>& _PUnits, std::vector<Unit*>& _EUnits)
{
    std::ifstream fin(filename);
    fin.open("status.txt");

    if (!fin.is_open())
    {
        std::cerr << "Blad przy otwarciu pliku: status.txt" << '\n';
        fin.clear();
        exit(EXIT_FAILURE);
    }

    while (!fin.eof())
    {
        long gold;
        fin >> gold;
        char side, type;
        int id, x, y, health;
        fin >> side;

        if (side == 'P' || side == 'E')
        {
            fin >> type >> id >> x >> y >> health;
            Unit* unit = nullptr;

            switch (type)
            {
                case 'K':
                    unit = new Knight();
                    break;
                case 'S':
                    unit = new Swordsman();
                    break;
                case 'A':
                    unit = new Archer();
                    break;
                case 'P':
                    unit = new Pikeman();
                    break;
                case 'R':
                    unit = new Ram();
                    break;
                case 'C':
                    unit = new Catapult();
                    break;
                case 'W':
                    unit = new Worker();
                    break;
                case 'B':
                    unit = new Base();
                    break;
                default:
                    std::cerr << "Nieznany typ jednostki" << '\n';
                    exit(EXIT_FAILURE);
            }

            if (side == 'P')
                _PUnits.push_back(unit);
            else
                _EUnits.push_back(unit);
        }
    }

    fin.clear();
    fin.close();
}

// Definicja funkcji TypePicker do wyboru typu jednostki na podstawie znaku
int TypePicker(char c)
{
    switch (c)
    {
        case 'K':
            return 0;
        case 'S':
            return 1;
        case 'A':
            return 2;
        case 'P':
            return 3;
        case 'R':
            return 4;
        case 'C':
            return 5;
        case 'W':
            return 6;
        case 'B':
            return 7;
        default:
            return -1;
    }
}