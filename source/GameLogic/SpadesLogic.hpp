#ifndef SPADESLOGIC_HPP
#define SPADESLOGIC_HPP

#include "source/PlayerAPI/Game.hpp"
#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

class Spades : public Game
{
public:
  void setDeck();
  bool validMove();
  void receiveValidMove(Card);
  void receiveBid(int);
  int getTrickWinner(std::vector<Card>, int);
  int getNextPlayer(int);
  void setTrick(std::vector<Card> v) { trick = v; }
  void setLedSuit(Suit);
  void setTurn(int t) { turn = t; }
  void setBrokenSpades(bool b) { spadesBroken = b; }
  int getTurn() { return turn; }
  void deal();
  void score();
  void startNewRound();
  void roundOver();
  void start();
  Spades(){};
  Spades(std::vector<std::shared_ptr<Player>>&);
  ~Spades(){}
private:
  int starter;
  bool spadesBroken;
  std::vector<Card> trick;
  Suit ledSuit;
  int trickWinner;
};
#endif
