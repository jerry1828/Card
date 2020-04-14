#ifndef CARD_CST_HPP
#define CARD_CST_HPP

//typedefs
using UInt = unsigned int;

//followings are prefixed with Card
//thus fixing class naming conflicts
enum class CardShape {

  RectRounded // Rectangle, Rounded extremity

};


//should be coupled or tupled with
//CardNumber a.k.a Number (Number::One)
enum class CardFigure {

  None = 1,
  JCommand,
  Queen,
  King,
  Lion

};


//card material
enum class CardType {

  Plastic,
  Paper
  
};


enum class CardNumber {

  One = 1,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten
};

//meaningful inner symbol colors
enum class CardColor {

  Red,
  Black
};


//should count the number of symbols
//as well
//Inner symbols, flowers
enum class CardSymbol {

  Square,
  Trefle,
  Coeur,
  Pique
};

#endif
