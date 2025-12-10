#include "GameSnapshot.h"
#include <fstream>
#include <iostream>
#include <sstream>

void GameSnapshot::capture(
    const Paletka& paletka,
    const Pilka& pilka,
    const std::vector<Stone>& bloki)
{
    paddlePosition = { paletka.getX(), paletka.getY() };
    ballPosition = { pilka.getX(), pilka.getY() };
    ballVelocity = { pilka.getVx(), pilka.getVy() };

    blocks.clear();
    for (const auto& b : bloki)
    {
        BlockData d;
        d.x = b.getPosition().x;
        d.y = b.getPosition().y;
        d.hp = b.getHP();
        blocks.push_back(d);
    }
}


bool GameSnapshot::saveToFile(const std::string& path) const
{
    std::ofstream out(path);
    if (!out.is_open()) {
        std::cerr << "Save: nie mozna otworzyc pliku: " << path << "\n";
        return false;
    }

    out << "PADDLE " << paddlePosition.x << " " << paddlePosition.y << "\n";
    out << "BALL " << ballPosition.x << " " << ballPosition.y << " "
        << ballVelocity.x << " " << ballVelocity.y << "\n";

    out << "BLOCKS " << blocks.size() << "\n";
    for (const auto& b : blocks) {
        out << "BLOCK " << b.x << " " << b.y << " " << b.hp << "\n";
    }

    out.close();
    return true;
}

bool GameSnapshot::loadFromFile(const std::string& path)
{
    std::ifstream in(path);
    if (!in.is_open()) {
        std::cerr << "Load: nie mozna otworzyc pliku: " << path << "\n";
        return false;
    }

    blocks.clear();

    std::string line;
    while (std::getline(in, line))
    {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string tag;
        ss >> tag;
        if (tag == "PADDLE") {
            ss >> paddlePosition.x >> paddlePosition.y;
        }
        else if (tag == "BALL") {
            ss >> ballPosition.x >> ballPosition.y >> ballVelocity.x >> ballVelocity.y;
        }
        else if (tag == "BLOCKS") {
            size_t n = 0;
            ss >> n;
            
            for (size_t i = 0; i < n; ++i) {
                if (!std::getline(in, line)) break;
                if (line.empty()) { --i; continue; }
                std::istringstream ss2(line);
                std::string tag2;
                ss2 >> tag2;
                if (tag2 != "BLOCK") { --i; continue; }
                BlockData bd;
                ss2 >> bd.x >> bd.y >> bd.hp;
                blocks.push_back(bd);
            }
        }
        else {
            
        }
    }

    in.close();
    return true;
}
