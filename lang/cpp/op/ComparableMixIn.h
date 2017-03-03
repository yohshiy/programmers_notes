/// @file
/// Comparable Mix-in 
///
/// @author M. Yoshida<yohshiy@gmail.com>
///
/// MIT License
///


#ifndef __COMPARABLE_MIX_IN_H__
#define __COMPARABLE_MIX_IN_H__

/// 比較可能にする Mix-in
template <class T>
class ComparableMixIn
{
 public:
  /// 比較用関数
  ///
  /// | 状態               |  戻り値  |
  /// |--------------------|----------|
  /// | other の方が大きい | 負の値   |
  /// | other と一致       |    0     |
  /// | other の方が小さい | 正の値   |
  /// 
  virtual int Compare(const T &other) const = 0;


  // 演算子の実装
  bool operator==(const T &other) const { return Compare(other) == 0; };
  bool operator!=(const T &other) const { return Compare(other) != 0; };
  bool operator< (const T &other) const { return Compare(other) <  0; };
  bool operator<=(const T &other) const { return Compare(other) <= 0; };
  bool operator> (const T &other) const { return Compare(other) >  0; };
  bool operator>=(const T &other) const { return Compare(other) >= 0; };
};

#endif

