/*
 * pairʵ��
 * make_pair() ����pair����
 * ��������ض����������� == != < <= > >=
 */

#ifndef __SGI_STL_INTERNAL_PAIR_H
#define __SGI_STL_INTERNAL_PAIR_H

__STL_BEGIN_NAMESPACE

//ģ��ṹ��
//����pair�ṹ������ΪT1 T2
template <class _T1, class _T2>
struct pair {
  //���͸��� typedef
  typedef _T1 first_type;
  typedef _T2 second_type;

  _T1 first;  //��һ��Ԫ��
  _T2 second;//�ڶ���Ԫ��
  //���캯��
  pair() : first(_T1()), second(_T2()) {}
  //���캯��
  pair(const _T1& __a, const _T2& __b) : first(__a), second(__b) {}

#ifdef __STL_MEMBER_TEMPLATES
  //�������캯��
  template <class _U1, class _U2>
  pair(const pair<_U1, _U2>& __p) : first(__p.first), second(__p.second) {}
#endif
};

//�ⲿ�������� ���������
//==�����
template <class _T1, class _T2>
inline bool operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{
    //�Ƚ�first��second
  return __x.first == __y.first && __x.second == __y.second; 
}

//<����� const �������治���޸�__x��ֵ
template <class _T1, class _T2>
inline bool operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ 
  return __x.first < __y.first || 
         (!(__y.first < __x.first) && __x.second < __y.second); 
}

#ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER

//!=�����
template <class _T1, class _T2>
inline bool operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__x == __y);
}

//>
template <class _T1, class _T2>
inline bool operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return __y < __x;
}

//<=
template <class _T1, class _T2>
inline bool operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__y < __x);
}

//>=
template <class _T1, class _T2>
inline bool operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__x < __y);
}

#endif /* __STL_FUNCTION_TMPL_PARTIAL_ORDER */

//make_pair������make_shard�������� ����������ض���
template <class _T1, class _T2>
inline pair<_T1, _T2> make_pair(const _T1& __x, const _T2& __y)
{
  return pair<_T1, _T2>(__x, __y);
}

__STL_END_NAMESPACE

#endif /* __SGI_STL_INTERNAL_PAIR_H */

// Local Variables:
// mode:C++
// End:
