#pragma once

//this code belongs to S.KOUAM
//the usage of the following source code
//should required the author permission
//embodies card definition dedicated 
//pour Che Guems and Bagarre card games

#include "cardcst.hpp"

#include <string>
#include <iostream>


using std::ostream;


//TODO
//gathered in a dedicated file
using Number = CardNumber;
using Color  = CardColor;
using Type   = CardType;
using Shape  = CardShape;
using Symbol = CardSymbol;
using Figure = CardFigure;



class Card {

  private :

    Number        m_number;
    Color         m_color;
    Type          m_type;
    Shape         m_form;
    Symbol        m_symbol;
    Figure        m_figure;

    std::string   m_name; //TODO, omitted
    static UInt m_realnoc;

  private :

    void Init()  noexcept;
    void Reset() noexcept;

    //to be called in ctrs with params.
    void Build(const Number _num,
               const Color  _colo,
               const Type   _typ,
               const Shape  _shape,
               const Symbol _symb,
               const Figure _fig);

    //to be called pour unique card
    //construction
    // n * 54 cards total
    //n : number of packs of cards
    void Build(const Number _num,
               const UInt   _numpack,
               const Color  _colo,
                     Symbol _symb,
                     Figure _fig);

    void Build(const Number _num,
               const Color  _colo,
                     Symbol _symb,
                     Figure _fig);


    //same cards colors
    constexpr bool SameColor(const Card& _card) const {
      bool Sameclr(false);
      
      const Color cardccurrent = m_color;
      const Color cardc        = _card.m_color;

      Sameclr = (cardccurrent == cardc);

      return Sameclr;
    }

    //same card symbols
    constexpr bool SameSymbol(const Card& _card) const {

      bool SameInnerCSymbol(false);

      const Symbol SamecInnerCurrent = m_symbol;
      const Symbol SamecInner        = _card.m_symbol;
      SameInnerCSymbol = (SamecInnerCurrent == SamecInner);
      return SameInnerCSymbol;
    }

  protected :
    //followings arithmetical methods 
    //don't considered cards colors, symbols
    //TOIM : constexpr introduce a bug in C++14
    constexpr bool Superior(const Card& _card) const;

    constexpr bool Inferior(const Card& _card) const;

    // are cards equal ?
    //TODO
    //TOFI
    constexpr bool Equal(const Card& _card) const;

    //the followings are replacement methods
    //working with all Card attributes
    //TODO thread safety
    void Copy(const Card& _card); //consider the fact that a card is unique
    void Move(Card&& _card); //TODO TOIM

  public :

    Card();//y having it private is an issue?
    //TOFI
    //precedence to be applied
    Card(const Number _number,
         const Color  _color,
               Symbol _symbol,
               Figure _figure = Figure::None);

    //handle the case with a figure
    Card(const Number _num,
         const UInt   _numpack,
         const Color  _colo,
               Symbol _symb,
               Figure _fig = Figure::None);

    Card(const Number _number,
         const Color  _color,
         const Type   _type,
         const Shape  _form,
         const Symbol _symbol,
         const Figure _figure = Figure::None);

   ~Card();
    //for Card card{}; decl. init.
  private :

    //Card(const Card&); //TODO //PRI
  public :
    //Card(Card&&); // needed with new operator ??

  public :

    constexpr Number GetNumber() const { return m_number; }
    constexpr Color  GetColor()  const { return m_color;  }
    constexpr Figure GetFigure() const { return m_figure; }
    constexpr Symbol GetSymbol() const { return m_symbol; }

    constexpr Type GetType() const {   return m_type; }
    constexpr Shape GetShape() const { return m_form; }

    constexpr UInt GetRealnoc() const { return m_realnoc; }
    //TOFI TOIM
    //coding rules, setters can not change 2 attr.
    void SetNumber(const Number _numb) {
      m_number = _numb;
      m_figure = Figure::None;
    }
    //TOFI TOIM
    void SetColor(const Color _colo) {
      m_color = _colo;
    }
    //TOFI TOIM
    void SetType(const Type _typ) {
      m_type = _typ;
    }

    //card comparator dedicated pour
    //bagarre card game
    bool operator<(const Card& _card);

    bool operator>(const Card& _card);

    bool operator==(const Card& _card);

    //assign a simple copy...?
    Card& operator=(const Card&);
};


std::ostream& operator<<(std::ostream&, const Number);
std::ostream& operator<<(std::ostream&, const Color);
std::ostream& operator<<(std::ostream&, const Type);
std::ostream& operator<<(std::ostream&, const Shape);
std::ostream& operator<<(std::ostream&, const Symbol);
std::ostream& operator<<(std::ostream&, const Figure);
//TOIM
std::ostream& operator<<(std::ostream&, const Card&);
