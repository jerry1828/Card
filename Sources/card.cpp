#include "card.hpp"


using namespace std;


Card::Card() {

  Init();
}


Card::Card(const Number _numb,
           const Color  _colo,
                 Symbol _symb,
                 Figure _fig) {
  Init();

  Build(_numb,
        _colo,
        _symb,
        _fig);
}


Card::Card(const Number _number,
           const Color  _color,
           const Type   _type,
           const Shape  _form,
           const Symbol _symbol,
           const Figure _figure) {

  Init();

  Build(_number,
        _color,
        _type,
        _form,
        _symbol,
        _figure);
}


Card::~Card() {

  Reset();
}


void
Card::Init() noexcept {

  m_number = Number::Two;
  m_color  = Color::Black;
  m_type   = Type::Plastic;
  m_form   = Shape::RectRounded;
  m_symbol = Symbol::Trefle;
  m_figure = Figure::None;//exception to be use, figure doesn't have number
}


void
Card::Reset() noexcept {

  m_number = Number::Two;
  m_figure = Figure::None;
}

//TODO takes arguments
void
Card::Build(const Number _num,
            const Color  _colo,
                  Symbol _symb,
                  Figure _fig)  {

  m_number = _num;
  m_color  = _colo;
  m_symbol = _symb;
  m_figure = _fig;
}


//TOIM constness builder
void
Card::Build(const Number _num,
            const Color  _colo,
            const Type   _typ,
            const Shape  _shape,
            const Symbol _symb,
            const Figure _fig)  {

  m_number = _num;
  m_color  = _colo;
  m_type   = _typ,
  m_form   = _shape,
  m_symbol = _symb;
  m_figure = _fig;
}


bool
Card::Equal(const Card& _card) const {

  bool Eqlr(false);

  const Figure cfcurrent = m_figure;
  const Figure cfinput   = _card.m_figure;

  switch (cfcurrent) {

    case Figure::None :
      {
        const Number cncurrent = m_number;
        const Number cninput   = _card.m_number;
        if (cfinput == Figure::JCommand ||
            cfinput == Figure::Queen    ||
            cfinput == Figure::King     ||
            cfinput == Figure::Lion) {
              Eqlr = false;
        }
        else if (cfinput == Figure::None) {
          Eqlr = (cncurrent == cninput);
        }
      }
    break;
    case Figure::JCommand :
    case Figure::Queen :
    case Figure::King :
    case Figure::Lion :
      {
        Eqlr = (cfcurrent == cfinput);
      }
    break;
  }

  const bool cEqlr(Eqlr);
  return cEqlr;
}


bool
Card::Inferior(const Card& _card) const {
  bool Inflr(true);

  const Figure cfcurrent = m_figure;
  const Figure rcf       = _card.m_figure;

  switch (cfcurrent) {
    case Figure::None :
      {
        const Number cncurrent = m_number;
        const Number rcn       = _card.m_number;
        if (rcf == Figure::None) {
          Inflr = (cncurrent < rcn);
        }
        else {
          Inflr = false;
        }
      }
    break;
    case Figure::JCommand :
      {
        if (rcf == Figure::None) {
               Inflr = false; 
        }
        else if (rcf == Figure::JCommand ||
                 rcf == Figure::Queen    ||
                 rcf == Figure::King     ||
                 rcf == Figure::Lion) {
          Inflr = true;    
        }
          }
    break;
    case Figure::Queen :
      {
        if (rcf == Figure::None     ||
            rcf == Figure::JCommand ||
            rcf == Figure::Queen) {
           Inflr = false;
         }
         else if (rcf == Figure::King ||
                     rcf == Figure::Lion) {
           Inflr = true;
         }
      }
    break;
    case Figure::King :
      {
        if (rcf == Figure::None ||
            rcf == Figure::JCommand ||
            rcf == Figure::Queen) {
              Inflr = true;  
        }
        else if (rcf == Figure::King ||
                 rcf == Figure::Lion) {
          Inflr = false; 
        }
      }
    break;
    case Figure::Lion :
      {
        if (rcf == Figure::None     ||
            rcf == Figure::JCommand ||
            rcf == Figure::Queen    ||
            rcf == Figure::Lion) {
           Inflr = false; 
         }
      }
    break;
  }

  const bool cInflr(Inflr);
  return cInflr;
}


bool
Card::Superior(const Card& _card) const { 
  bool Suplr(true);

  const Figure cfcurrent = m_figure;
  const Figure rcf       = _card.m_figure;
  switch (cfcurrent) {

    case Figure::None :
      {
        const Number lcn = m_number;
        const Number rcn = _card.m_number;
        if (rcf == Figure::None) {
          Suplr = (lcn > rcn);
        }
        else {
          Suplr = false;
        }
        }
    break;
    case Figure::JCommand :
      {
        if (rcf == Figure::None) {
              Suplr = true;
        }
        else if (rcf == Figure::JCommand ||
                 rcf == Figure::Queen    ||
                 rcf == Figure::King     ||
                 rcf == Figure::Lion) {
              Suplr = false;
        }
      }
    break;
    case Figure::Queen :
      {
        if (rcf == Figure::None ||
            rcf == Figure::JCommand) {
              Suplr = true;
        }
        else if (rcf == Figure::Queen ||
                 rcf == Figure::King  ||
                 rcf == Figure::Lion) {
          Suplr = false;
        }
      } 
    break;
    case Figure::King :
      {
        if (rcf == Figure::None     ||
            rcf == Figure::JCommand ||
            rcf == Figure::Queen) {
                Suplr = true;
        }
        else if (rcf == Figure::King ||
                 rcf == Figure::Lion) {
          Suplr = false;
        }
      }
    break;
    case Figure::Lion :
      {
        if (rcf == Figure::None     ||
            rcf == Figure::JCommand ||
            rcf == Figure::Queen    ||
            rcf == Figure::King) {
              Suplr = true;
        }
        else if (rcf == Figure::Lion) {
          Suplr = false;
        }
      }
    break;
  }

  const bool cSuplr(Suplr);
  return cSuplr;
}


bool
Card::operator<(const Card& _card) {

  const bool cInflr=this->Inferior(_card);
  return cInflr;
}


bool Card::operator>(const Card& _card) {

  const bool cSuplr=this->Superior(_card);
  return cSuplr;
}


bool Card::operator==(const Card& _card) {

  const bool cEqulr=this->Equal(_card);
  return cEqulr;
}


ostream& operator<<(ostream& _os, const Number _numb) {

  _os << _numb;
  return _os;
}


ostream& operator<<(ostream& _os, const Color _colo) {

  _os << _colo;
  return _os;
}


ostream& operator<<(ostream& _os, const Type _typ) {

  _os << _typ;
  return _os;
}


ostream& operator<<(ostream& _os, const Shape _form) {

  _os << _form;
  return _os;
}


ostream& operator<<(ostream& _os, const Symbol _symb) {

  _os << _symb;
  return _os;
}


ostream& operator<<(ostream& _os, const Figure _fig) {

  _os << _fig;
  return _os;
}


//TOIM
ostream& operator<<(ostream& _os, const Card& _card) {

  _os << _card.GetNumber();
  _os << _card.GetColor();
  _os << _card.GetType(); //paper or plastic
  _os << _card.GetShape(); //form
  _os << _card.GetSymbol();
  _os << _card.GetFigure();//can be None

  return _os;
}
