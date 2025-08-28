#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>

#include "Weapon.hpp"

class HumanA {
   public:
    HumanA(std::string name, Weapon &weapon);
    void attack(void) const;

   private:
    std::string name;
    Weapon &weapon;
};

#endif /* HUMANA_HPP */

// 参照は初期化時にのみ束縛される -
// 	参照は宣言と同時に必ず初期化する必要があり、後から別のオブジェクトを参照することはできません
// 参照への代入は不可能 -
// 	一度初期化された参照は、その後別のオブジェクトを参照するように変更できません
// メンバイニシャライザーリストが必須 -
// 	参照型のメンバ変数は、コンストラクターのメンバイニシャライザーリストで初期化する必要があります