#ifndef DirectedMap_h
#define DirectedMap_h

#include "BinarySearchTrees.h"


template <typename KK, typename VV>
class OrderedMap: public SearchTree<Entry<KK,VV>> {
public:
    // Usefull Typedef
    typedef  SearchTree<Entry<KK,VV>> BST;
    typedef typename SearchTree<Entry<KK,VV>>::Iterator BSTIterator;

public:
    OrderedMap(): SearchTree<Entry<KK,VV>>(){}
    int size () const ;
    bool empty () const ;
    BSTIterator find ( const KK& k) const {return find(k);}
    BSTIterator put ( const KK& k, const VV& v){return BST::insert(k,v) ;}
    void erase ( const KK& k) ;
    void erase ( const BSTIterator & p);
    BSTIterator begin () {return BST::begin(); }
    BSTIterator end () {return BST::end();}
	BSTIterator lowerEntry(int k)
	{
		BSTIterator f = BST::finder2(k, BST::root());
		if (f.v.isExternal() || f.v.left().isExternal())
		{
			while (f.v.v->elt.key() != BST::root().v->elt.key())
			{
				if (f.v == f.v.parent().right())
				{
					f.v = f.v.parent();
					return f;
				}
				f.v = f.v.parent();
			}
		}
		else if (f.v.left().isInternal())
		{
			f.v = f.v.left();
			while (f.v.right().isInternal())
			{
				f.v = f.v.right();
			}
			return f;
		}
		return BST::end();
	}

	BSTIterator floorEntry(int k)
	{
		BSTIterator f = BST::finder2(k, BST::root());
		if (f.v.v->elt.key() == k)
		{
			return f;
		}
		if (f.v.isExternal() || f.v.left().isExternal()) 
		{
			while (f.v.v->elt.key() != BST::root().v->elt.key())
			{
				if (f.v == f.v.parent().right())
				{
					f.v = f.v.parent();
					return f;
				}
				f.v = f.v.parent();
			}
		}
		else if(f.v.left().isInternal())
		{
			f.v = f.v.left();
			while (f.v.right().isInternal())
			{
				f.v = f.v.right();
			}
			return f;
		}
		return BST::end();
	}

	BSTIterator higherEntry(int k)
	{
		BSTIterator f = BST::finder2(k, BST::root());
		if (f.v.isExternal() || f.v.right().isExternal())
		{
			while (f.v.v->elt.key() != BST::root().v->elt.key())
			{
				if (f.v == f.v.parent().left())
				{
					f.v = f.v.parent();
					return f;
				}
				f.v = f.v.parent();
			}
		}
		else if (f.v.right().isInternal())
		{
			f.v = f.v.right();
			while (f.v.left().isInternal())
			{
				f.v = f.v.left();
			}
			return f;
		}
		return BST::end();
	}

	BSTIterator ceilingEntry(int k)
	{
		BSTIterator f = BST::finder2(k, BST::root());
		if (f.v.v->elt.key() == k)
		{
			return f;
		}
		if (f.v.isExternal() || f.v.right().isExternal())
		{
			while (f.v.v->elt.key() != BST::root().v->elt.key())
			{
				if (f.v == f.v.parent().left())
				{
					f.v = f.v.parent();
					return f;
				}
				f.v = f.v.parent();
			}
		}
		else if (f.v.right().isInternal())
		{
			f.v = f.v.right();
			while (f.v.left().isInternal())
			{
				f.v = f.v.left();
			}
			return f;
		}
		return BST::end();
	}


	BSTIterator firstEntry() {
		if (empty()) {
			return end();
		}
		else {
			return begin();
		}
	};
	BSTIterator lastEntry() {
		typedef typename SearchTree<Entry<KK, VV>>::TPos IP;
		if (empty()) {
			return end();
		}
		else {
			BSTIterator s = end();
			IP pi = s.v;
			IP lpi = pi.left();
			while (lpi.isInternal()) lpi = lpi.right();
			return BSTIterator(lpi.parent());
		}
	}





} ;



template <typename KK, typename VV>
int OrderedMap<KK,VV>::size() const {return SearchTree<Entry<KK,VV>>::getSize() ;}

template <typename KK, typename VV>
bool OrderedMap<KK,VV>::empty() const {return SearchTree<Entry<KK,VV>>::isEmpty() ; }


#endif /* DirectedMap_h */


