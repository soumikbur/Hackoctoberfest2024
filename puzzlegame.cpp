#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

const int BOARD_SIZE = 4;  // 4x4 grid
const int TILE_SIZE = 100;

class PuzzleGame {
public:
    PuzzleGame() : window(sf::VideoMode(BOARD_SIZE * TILE_SIZE, BOARD_SIZE * TILE_SIZE), "Sliding Puzzle Game") {
        setupBoard();
        shuffleBoard();
    }

    void run() {
        while (window.isOpen()) {
            processEvents();
            window.clear();
            drawBoard();
            window.display();
        }
    }

private:
    sf::RenderWindow window;
    std::vector<std::vector<int>> board;
    int emptyX, emptyY;  // Empty space coordinates

    void setupBoard() {
        int count = 1;
        board.resize(BOARD_SIZE, std::vector<int>(BOARD_SIZE));
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (i == BOARD_SIZE - 1 && j == BOARD_SIZE - 1) {
                    board[i][j] = 0;  // Empty tile
                    emptyX = i;
                    emptyY = j;
                } else {
                    board[i][j] = count++;
                }
            }
        }
    }

    void shuffleBoard() {
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < 100; i++) {
            int dx = rand() % 2 ? (rand() % 2 ? 1 : -1) : 0;
            int dy = dx == 0 ? (rand() % 2 ? 1 : -1) : 0;
            moveTile(emptyX + dx, emptyY + dy);
        }
    }

    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                handleInput(event.key.code);
        }
    }

    void handleInput(sf::Keyboard::Key key) {
        if (key == sf::Keyboard::Up) moveTile(emptyX + 1, emptyY);
        else if (key == sf::Keyboard::Down) moveTile(emptyX - 1, emptyY);
        else if (key == sf::Keyboard::Left) moveTile(emptyX, emptyY + 1);
        else if (key == sf::Keyboard::Right) moveTile(emptyX, emptyY - 1);
    }

    void moveTile(int x, int y) {
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
            std::swap(board[emptyX][emptyY], board[x][y]);
            emptyX = x;
            emptyY = y;
        }
    }

    void drawBoard() {
        sf::Font font;
        font.loadFromFile("arial.ttf");  // Use any font file you have

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == 0) continue;  // Skip empty tile

                sf::RectangleShape tile(sf::Vector2f(TILE_SIZE - 5, TILE_SIZE - 5));
                tile.setPosition(j * TILE_SIZE, i * TILE_SIZE);
                tile.setFillColor(sf::Color::White);
                window.draw(tile);

                sf::Text text;
                text.setFont(font);
                text.setString(std::to_string(board[i][j]));
                text.setCharacterSize(40);
                text.setFillColor(sf::Color::Black);
                text.setPosition(j * TILE_SIZE + 20, i * TILE_SIZE + 10);
                window.draw(text);
            }
        }
    }
};

int main() {
    PuzzleGame game;
    game.run();
    return 0;
}
