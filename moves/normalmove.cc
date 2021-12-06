#include "normalmove.h"

#include "../pieces/piece.h"

NormalMove::NormalMove(Piece &piece, int oldRank, int oldFile, int newRank, int newFile, Piece *capturedPiece, bool check)
    : Move{check}, piece{piece}, oldRank{oldRank}, oldFile{oldFile}, newRank{newRank}, newFile{newFile}, capturedPiece{capturedPiece} {}

Piece &NormalMove::getPiece() {
    return piece;
}

int NormalMove::getOldRank() {
    return oldRank;
}

int NormalMove::getOldFile() {
    return oldFile;
}

int NormalMove::getNewRank() {
    return newRank;
}

int NormalMove::getNewFile() {
    return newFile;
}

Piece *NormalMove::getCapturedPiece() {
    return capturedPiece;
}

void NormalMove::makeMove(Board &board){
    if (capturedPiece != nullptr) {
        capturedPiece->setCaptured(true);
    }
    piece.setRank(newRank);
    piece.setFile(newFile);
}

void NormalMove::undo(Board &board){}