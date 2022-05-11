#include "board.h"

#include <iostream>
#include <cinttypes>
#include <array>
#include <vector>
#include <memory>


Board::Board(uint8_t board_rows, uint8_t board_columns)  {
    rows = board_rows;
    columns = board_columns;
    content.resize(rows * columns);
    for(int i = 0; i < rows * columns; i++)
        content[i] = 0;
}
Board::Board() {
    this->rows = 5;
    this->columns = 7;
    this->content.resize(rows * columns);
    for(int i = 0; i < rows * columns; i++)
        this->content[i] = 0;
}
// getters
uint16_t Board::get_columns(void) { return columns; }
uint16_t Board::get_rows(void) { return rows; }

bool Board::drop_chip(uint16_t col, uint8_t player) {
    if(col > this->columns)
        return false;

    for(uint16_t row = rows - 1; row < rows; row--) {
        if((*this)[row][col] == 0) {
            (*this)[row][col] = player;
            return true;
        }
    }
    return false;
}

std::vector<uint8_t>::iterator Board::operator[] (int index) {
    return this->content.begin() + index * this->columns;
}
