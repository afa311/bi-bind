#ifndef BIND_H_INCLUDED
#define BIND_H_INCLUDED

#if defined(_MSC_VER)
# if (_MSC_VER >= 1020)
#  pragma once
# endif
# pragma warning(push)
# pragma warning(disable: 4512) // assignment operator could not be generated
#endif

namespace bi
{
    template<int I> struct Argc{};
    template<typename T> struct type{};
    template<typename R, typename F, typename L> struct bind_t;
    template<typename R, typename C, typename L> struct mem_bind_t;

    template<typename T> struct untie_ref
    {
        typedef T type;
    };
    template<typename T> struct untie_ref<T&> : untie_ref<T>{};

    template<typename T> struct param_traits
    {
        typedef typename untie_ref<T>::type &type;
    };

    template<class R> struct result_traits
    {
        typedef R type;
    };
    template<class F> struct result_traits<type<F> > : result_traits<typename F::result_type> {};

    template<typename R, typename F> struct f_i
    {
        typedef typename result_traits<R>::type result_type;

    protected:
        explicit f_i(const F &f) : f_(f) {}
        F f_;
    };

    template<typename T>
    inline T* get_pointer(T *o){return o;}

    template<typename R, typename C, typename F>
    struct f_cplus_0 : f_i<R, F>
    {
        typedef f_i<R, F> base;

        explicit f_cplus_0(const F &f) : base(f) {}

        template<typename U>
        inline typename base::result_type operator()(U &u) const
        {
            return (get_pointer(u)->*base::f_)();
        }

        inline typename base::result_type operator()(C &c) const
        {
            return (c.*base::f_)();
        }
    };

    template<typename R, typename C, typename F>
    struct f_cplus_1 : f_i<R, F>
    {
        typedef f_i<R, F> base;

        explicit f_cplus_1(const F &f) : base(f) {}

        template<typename U, typename A1>
        inline typename base::result_type operator()(U &u, A1 a1) const
        {
            return (get_pointer(u)->*base::f_)(a1);
        }

        template<typename A1>
        inline typename base::result_type operator()(C &c, A1 a1) const
        {
            return (c.*base::f_)(a1);
        }
    };

    template<typename R, typename C, typename F>
    struct f_cplus_2 : f_i<R, F>
    {
        typedef f_i<R, F> base;

        explicit f_cplus_2(const F &f) : base(f) {}

        template<typename U, typename A1, typename A2>
        inline typename base::result_type operator()(U &u, A1 a1, A2 a2) const
        {
            return (get_pointer(u)->*base::f_)(a1, a2);
        }

        template<typename A1, typename A2>
        inline typename base::result_type operator()(C &c, A1 a1, A2 a2) const
        {
            return (c.*base::f_)(a1, a2);
        }
    };

    template<typename R, typename C, typename F>
    struct f_cplus_3 : f_i<R, F>
    {
        typedef f_i<R, F> base;

        explicit f_cplus_3(const F &f) : base(f) {}

        template<typename U, typename A1, typename A2, typename A3>
        inline typename base::result_type operator()(U &u, A1 &a1, A2 &a2, A3 &a3) const
        {
            return (get_pointer(u)->*base::f_)(a1, a2, a3);
        }

        template<typename A1, typename A2, typename A3>
        inline typename base::result_type operator()(C &c, A1 &a1, A2 &a2, A3 &a3) const
        {
            return (c.*base::f_)(a1, a2, a3);
        }
    };

    template<typename R, typename C, typename F>
    struct f_cplus_4 : f_i<R, F>
    {
        typedef f_i<R, F> base;

        explicit f_cplus_4(const F &f) : base(f) {}

        template<typename U, typename A1, typename A2, typename A3, typename A4>
        inline typename base::result_type operator()(U &u, A1 &a1, A2 &a2, A3 &a3, A4 &a4) const
        {
            return (get_pointer(u)->*base::f_)(a1, a2, a3, a4);
        }

        template<typename A1, typename A2, typename A3, typename A4>
        inline typename base::result_type operator()(C &c, A1 &a1, A2 &a2, A3 &a3, A4 &a4) const
        {
            return (c.*base::f_)(a1, a2, a3, a4);
        }
    };

    template<typename R, typename C, typename F>
    struct f_cplus_5 : f_i<R, F>
    {
        typedef f_i<R, F> base;

        explicit f_cplus_5(const F &f) : base(f) {}

        template<typename U, typename A1, typename A2, typename A3, typename A4, typename A5>
        inline typename base::result_type operator()(U &u, A1 &a1, A2 &a2, A3 &a3, A4 &a4, A5 &a5) const
        {
            return (get_pointer(u)->*base::f_)(a1, a2, a3, a4, a5);
        }

        template<typename A1, typename A2, typename A3, typename A4, typename A5>
        inline typename base::result_type operator()(C &c, A1 &a1, A2 &a2, A3 &a3, A4 &a4, A5 &a5) const
        {
            return (c.*base::f_)(a1, a2, a3, a4, a5);
        }
    };

    template<typename R, typename C, typename F>
    struct f_cplus_6 : f_i<R, F>
    {
        typedef f_i<R, F> base;

        explicit f_cplus_6(const F &f) : base(f) {}

        template<typename U, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
        inline typename base::result_type operator()(U &u, A1 &a1, A2 &a2, A3 &a3, A4 &a4, A5 &a5, A6 &a6) const
        {
            return (get_pointer(u)->*base::f_)(a1, a2, a3, a4, a5, a6);
        }

        template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
        inline typename base::result_type operator()(C &c, A1 &a1, A2 &a2, A3 &a3, A4 &a4, A5 &a5, A6 &a6) const
        {
            return (c.*base::f_)(a1, a2, a3, a4, a5, a6);
        }
    };

    template<typename R, typename C, typename F>
    struct f_cplus_7 : f_i<R, F>
    {
        typedef f_i<R, F> base;

        explicit f_cplus_7(const F &f) : base(f) {}

        template<typename U, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
        inline typename base::result_type operator()(U &u, A1 &a1, A2 &a2, A3 &a3, A4 &a4, A5 &a5, A6 &a6, A7 &a7) const
        {
            return (get_pointer(u)->*base::f_)(a1, a2, a3, a4, a5, a6, a7);
        }

        template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
        inline typename base::result_type operator()(C &c, A1 &a1, A2 &a2, A3 &a3, A4 &a4, A5 &a5, A6 &a6, A7 &a7) const
        {
            return (c.*base::f_)(a1, a2, a3, a4, a5, a6, a7);
        }
    };

    template<typename R, typename C, typename F>
    struct f_cplus_8 : f_i<R, F>
    {
        typedef f_i<R, F> base;

        explicit f_cplus_8(const F &f) : base(f) {}

        template<typename U, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
        inline typename base::result_type operator()(U &u, A1 &a1, A2 &a2, A3 &a3, A4 &a4, A5 &a5, A6 &a6, A7 &a7, A8 &a8) const
        {
            return (get_pointer(u)->*base::f_)(a1, a2, a3, a4, a5, a6, a7, a8);
        }

        template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
        inline typename base::result_type operator()(C &c, A1 &a1, A2 &a2, A3 &a3, A4 &a4, A5 &a5, A6 &a6, A7 &a7, A8 &a8) const
        {
            return (c.*base::f_)(a1, a2, a3, a4, a5, a6, a7, a8);
        }
    };

    template<typename R, typename C, typename F>
    struct f_cplus_9 : f_i<R, F>
    {
        typedef f_i<R, F> base;

        explicit f_cplus_9(const F &f) : base(f) {}

        template<typename U, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
        inline typename base::result_type operator()(U &u, A1 &a1, A2 &a2, A3 &a3, A4 &a4, A5 &a5, A6 &a6, A7 &a7, A8 &a8, A9 &a9) const
        {
            return (get_pointer(u)->*base::f_)(a1, a2, a3, a4, a5, a6, a7, a8, a9);
        }

        template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
        inline typename base::result_type operator()(C &c, A1 &a1, A2 &a2, A3 &a3, A4 &a4, A5 &a5, A6 &a6, A7 &a7, A8 &a8, A9 &a9) const
        {
            return (c.*base::f_)(a1, a2, a3, a4, a5, a6, a7, a8, a9);
        }
    };

    template<typename lt>
    struct list_av : lt
    {
        typedef lt base;
        list_av(const lt &ll) : base(ll) {}

        using base::operator[];

        template<typename T>
        inline T& operator[](T &v) const {return v;}

        template<typename T>
        inline const T& operator[](const T &v) const{ return v;}

        template<typename R, typename F, typename L>
        inline R operator[](const bind_t<R, F, L> &b) const
        {
            return b.eval(*this);
        }

        template<typename R, typename F, typename L>
        inline R operator[](bind_t<R, F, L> &b) const
        {
            return b.eval(*this);
        }
    };

    struct list0
    {
        inline void operator[](Argc<0>(*)()) const{};
        inline void operator[](Argc<0>) const{};

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L&)
        {
            return f();
        }

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L&) const
        {
            return f();
        }
    };

    template<typename D>
    struct list1b : list0
    {
        typedef list0 base;

        using base::operator[];

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l)
        {
            D &d = static_cast<D&>(*this); d;  //used C4189
            return f(l[d.a1_]);
        }

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l) const
        {
            const D &d = static_cast<const D&>(*this); d;  //used C4189
            return f(l[d.a1_]);
        }
    };

    template<typename A1>
    struct list1 : list1b<list1<A1> >
    {
        typedef list1b<list1<A1> > base;
        typedef typename param_traits<A1>::type P1;

        using base::operator[];

        explicit list1(P1 p1) : a1_(p1) {}
        inline P1 operator[](Argc<1>(*)()) const { return a1_;}
        inline P1 operator[](Argc<1>) const { return a1_;}

        A1 a1_;
    };

    template<int I>
    struct list1<Argc<I>(*)()> : list1b<list1<Argc<I>(*)()> >
    {
        typedef list1b<list1<Argc<I>(*)()> > base;
        typedef typename param_traits<Argc<I>(*)()>::type P1;

        using base::operator[];

        explicit list1(P1){}
        static Argc<I> a1_() {return Argc<I>();}
    };

    template<typename D, typename A1>
    struct list2b : list1<A1>
    {
        typedef list1<A1> base;
        using base::operator[];

        list2b(typename base::P1 p1) : base(p1){}

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l)
        {
            D &d = static_cast<D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_]);
        }

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l) const
        {
            const D &d = static_cast<const D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_]);
        }
    };

    template<typename A1, typename A2>
    struct list2 : list2b<list2<A1, A2>, A1>
    {
        typedef list2b<list2<A1, A2>, A1> base;
        typedef typename param_traits<A2>::type P2;

        using base::operator[];

        list2(typename base::P1 p1, P2 p2) : base(p1), a2_(p2) {}

        inline P2 operator[](Argc<2> (*)()) const { return a2_; }
        inline P2 operator[](Argc<2>) const { return a2_;}

        A2 a2_;
    };

    template<typename A1, int I>
    struct list2<A1, Argc<I>(*)()> : list2b<list2<A1, Argc<I>(*)()>, A1>
    {
        typedef list2b<list2<A1, Argc<I>(*)()>, A1> base;
        typedef typename param_traits<Argc<I>(*)()>::type P2;

        using base::operator[];

        list2(typename base::P1 p1, P2) : base(p1){}

        static Argc<I> a2_() { return Argc<I>(); }
    };

    template<typename D, typename A1, typename A2>
    struct list3b : list2<A1, A2>
    {
        typedef list2<A1, A2> base;
        using base::operator[];

        list3b(typename base::P1 p1, typename base::P2 p2) : base(p1, p2) {}

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l)
        {
            D &d = static_cast<D&>(*this); d;  //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_]);
        }

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l) const
        {
            const D &d = static_cast<const D&>(*this); d;  //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_]);
        }
    };

    template<typename A1, typename A2, typename A3>
    struct list3 : list3b<list3<A1, A2, A3>, A1, A2>
    {
        typedef list3b<list3<A1, A2, A3>, A1, A2> base;
        typedef typename param_traits<A3>::type P3;
        using base::operator[];

        list3(typename base::P1 p1, typename base::P2 p2, P3 p3) : base(p1, p2), a3_(p3) {}

        inline P3 operator[](Argc<3> (*)()) const { return a3_; }
        inline P3 operator[](Argc<3>) const { return a3_;}

        A3 a3_;
    };

    template<typename A1, typename A2, int I>
    struct list3<A1, A2, Argc<I>(*)()> : list3b<list3<A1, A2, Argc<I>(*)()>, A1, A2>
    {
        typedef list3b<list3<A1, A2, Argc<I>(*)()>, A1, A2> base;
        typedef typename param_traits<Argc<I>(*)()>::type P3;
        using base::operator[];

        list3(typename base::P1 p1, typename base::P2 p2, P3) : base(p1, p2) {}

        static Argc<I> a3_() { return Argc<I>(); }
    };

    template<typename D, typename A1, typename A2, typename A3>
    struct list4b : list3<A1, A2, A3>
    {
        typedef list3<A1, A2, A3> base;
        using base::operator[];

        list4b(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3) : base(p1, p2, p3){}

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l)
        {
            D &d = static_cast<D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_], l[d.a4_]);
        }

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l) const
        {
            const D &d = static_cast<const D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_], l[d.a4_]);
        }
    };

    template<typename A1, typename A2, typename A3, typename A4>
    struct list4 : list4b<list4<A1, A2, A3, A4>, A1, A2, A3>
    {
        typedef list4b<list4<A1, A2, A3, A4>, A1, A2, A3> base;
        typedef typename param_traits<A4>::type P4;
        using base::operator[];

        list4(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, P4 p4) : base(p1, p2, p3), a4_(p4) {}

        inline P4 operator[](Argc<4>(*)()) const { return a4_; }
        inline P4 operator[](Argc<4>) const { return a4_;}

        A4 a4_;
    };

    template<typename A1, typename A2, typename A3, int I>
    struct list4<A1, A2, A3, Argc<I>(*)()> : list4b<list4<A1, A2, A3, Argc<I>(*)()>, A1, A2, A3>
    {
        typedef list4b<list4<A1, A2, A3, Argc<I>(*)()>, A1, A2, A3> base;
        typedef typename param_traits<Argc<I>(*)()>::type P4;
        using base::operator[];

        list4(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, P4) : base(p1, p2, p3) {}

        static Argc<I> a4_() { return Argc<I>(); }
    };

    template<typename D, typename A1, typename A2, typename A3, typename A4>
    struct list5b : list4<A1, A2, A3, A4>
    {
        typedef list4<A1, A2, A3, A4> base;
        using base::operator[];

        list5b(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4) : base(p1, p2, p3, p4) { }

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l)
        {
            D &d = static_cast<D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_], l[d.a4_], l[d.a5_]);
        }

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l) const
        {
            const D &d = static_cast<const D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_], l[d.a4], l[d.a5_]);
        }
    };

    template<typename A1, typename A2, typename A3, typename A4, typename A5>
    struct list5 : list5b<list5<A1, A2, A3, A4, A5>, A1, A2, A3, A4>
    {
        typedef list5b<list5<A1, A2, A3, A4, A5>, A1, A2, A3, A4> base;
        typedef typename param_traits<A5>::type P5;
        using base::operator[];

        list5(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, P5 p5) : base(p1, p2, p3, p4), a5_(p5) { }

        inline P5 operator[](Argc<5> (*)()) const { return a5_; }
        inline P5 operator[](Argc<5>) const { return a5_;}

        A5 a5_;
    };

    template<typename A1, typename A2, typename A3, typename A4, int I>
    struct list5<A1, A2, A3, A4, Argc<I>(*)()> : list5b<list5<A1, A2, A3, A4, Argc<I>(*)()>, A1, A2, A3, A4>
    {
        typedef list5b<list5<A1, A2, A3, A4, Argc<I>(*)()>, A1, A2, A3, A4> base;
        typedef typename param_traits<Argc<I>(*)()>::type P5;
        using base::operator[];

        list5(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, P5) : base(p1, p2, p3, p4) {}

        static Argc<I> a5_() { return Argc<I>(); }
    };

    template<typename D, typename A1, typename A2, typename A3, typename A4, typename A5>
    struct list6b : list5<A1, A2, A3, A4, A5>
    {
        typedef list5<A1, A2, A3, A4, A5> base;
        using base::operator[];

        list6b(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, typename base::P5 p5) : base(p1, p2, p3, p4, p5) {}

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l)
        {
            D &d = static_cast<D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_], l[d.a4_], l[d.a5_], l[d.a6_]);
        }

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l) const
        {
            const D &d = static_cast<const D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_], l[d.a4_], l[d.a5_], l[d.a6_]);
        }
    };

    template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
    struct list6 : list6b<list6<A1, A2, A3, A4, A5, A6>, A1, A2, A3, A4, A5>
    {
        typedef list6b<list6<A1, A2, A3, A4, A5, A6>, A1, A2, A3, A4, A5> base;
        typedef typename param_traits<A6>::type P6;
        using base::operator[];

        list6(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, typename base::P5 p5, P6 p6) : base(p1, p2, p3, p4, p5), a6_(p6) {}

        inline P6 operator[](Argc<6> (*)()) const { return a6_; }
        inline P6 operator[](Argc<6>) const { return a6_;}

        A6 a6_;
    };

    template<typename A1, typename A2, typename A3, typename A4, typename A5, int I>
    struct list6<A1, A2, A3, A4, A5, Argc<I>(*)()> : list6b<list6<A1, A2, A3, A4, A5, Argc<I>(*)()>, A1, A2, A3, A4, A5>
    {
        typedef list6b<list6<A1, A2, A3, A4, A5, Argc<I>(*)()>, A1, A2, A3, A4, A5> base;
        typedef typename param_traits<Argc<I>(*)()>::type P6;
        using base::operator[];

        list6(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, typename base::P5 p5, P6) : base(p1, p2, p3, p4, p5) {}

        static Argc<I> a6_() { return Argc<I>(); }
    };

    template<typename D, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
    struct list7b : list6<A1, A2, A3, A4, A5, A6>
    {
        typedef list6<A1, A2, A3, A4, A5, A6> base;
        using base::operator[];

        list7b(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, typename base::P5 p5, typename base::P6 p6) : base(p1, p2, p3, p4, p5, p6) {}

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l)
        {
            D &d = static_cast<D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_], l[d.a4_], l[d.a5_], l[d.a6_], l[d.a7_]);
        }

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l) const
        {
            const D &d = static_cast<const D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_], l[d.a4_], l[d.a5_], l[d.a6_], l[d.a7_]);
        }
    };

    template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
    struct list7 : list7b<list7<A1, A2, A3, A4, A5, A6, A7>, A1, A2, A3, A4, A5, A6>
    {
        typedef list7b<list7<A1, A2, A3, A4, A5, A6, A7>, A1, A2, A3, A4, A5, A6> base;
        typedef typename param_traits<A7>::type P7;
        using base::operator[];

        list7(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, typename base::P5 p5, typename base::P6 p6, P7 p7) : base(p1, p2, p3, p4, p5, p6), a7_(p7) {}

        inline P7 operator[](Argc<7> (*)()) const { return a7_; }
        inline P7 operator[](Argc<7>) const { return a7_;}

        A7 a7_;
    };

    template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, int I>
    struct list7<A1, A2, A3, A4, A5, A6, Argc<I>(*)()> : list7b<list7<A1, A2, A3, A4, A5, A6, Argc<I>(*)()>, A1, A2, A3, A4, A5, A6>
    {
        typedef list7b<list7<A1, A2, A3, A4, A5, A6, Argc<I>(*)()>, A1, A2, A3, A4, A5, A6> base;
        typedef typename param_traits<Argc<I>(*)()>::type P7;
        using base::operator[];

        list7(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, typename base::P5 p5, typename base::P6 p6, P7) : base(p1, p2, p3, p4, p5, p6) {}

        static Argc<I> a7_() { return Argc<I>(); }
    };

    template<typename D, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
    struct list8b : list7<A1, A2, A3, A4, A5, A6, A7>
    {
        typedef list7<A1, A2, A3, A4, A5, A6, A7> base;
        using base::operator[];

        list8b(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, typename base::P5 p5, typename base::P6 p6, typename base::P7 p7) : base(p1, p2, p3, p4, p5, p6, p7) {}

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l)
        {
            D &d = static_cast<D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_], l[d.a4_], l[d.a5_], l[d.a6_], l[d.a7_], l[d.a8_]);
        }

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l) const
        {
            const D &d = static_cast<const D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_], l[d.a4_], l[d.a5_], l[d.a6_], l[d.a7_], l[d.a8_]);
        }
    };

    template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
    struct list8 : list8b<list8<A1, A2, A3, A4, A5, A6, A7, A8>, A1, A2, A3, A4, A5, A6, A7>
    {
        typedef list8b<list8<A1, A2, A3, A4, A5, A6, A7, A8>, A1, A2, A3, A4, A5, A6, A7> base;
        typedef typename param_traits<A8>::type P8;
        using base::operator[];

        list8(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, typename base::P5 p5, typename base::P6 p6, typename base::P7 p7, P8 p8) : base(p1, p2, p3, p4, p5, p6, p7), a8_(p8) {}

        inline P8 operator[](Argc<8> (*)()) const { return a8_; }
        inline P8 operator[](Argc<8>) const { return a8_;}

        A8 a8_;
    };

    template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, int I>
    struct list8<A1, A2, A3, A4, A5, A6, A7, Argc<I>(*)()> : list8b<list8<A1, A2, A3, A4, A5, A6, A7, Argc<I>(*)()>, A1, A2, A3, A4, A5, A6, A7>
    {
        typedef list8b<list8<A1, A2, A3, A4, A5, A6, A7, Argc<I>(*)()>, A1, A2, A3, A4, A5, A6, A7> base;
        typedef typename param_traits<Argc<I>(*)()>::type P8;
        using base::operator[];

        list8(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, typename base::P5 p5, typename base::P6 p6, typename base::P7 p7, P8) : base(p1, p2, p3, p4, p5, p6, p7) {}

        static Argc<I> a8_() { return Argc<I>(); }
    };

    template<typename D, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
    struct list9b : list8<A1, A2, A3, A4, A5, A6, A7, A8>
    {
        typedef list8<A1, A2, A3, A4, A5, A6, A7, A8> base;
        using base::operator[];

        list9b(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, typename base::P5 p5, typename base::P6 p6, typename base::P7 p7, typename base::P8 p8) : base(p1, p2, p3, p4, p5, p6, p7, p8) {}

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l)
        {
            D &d = static_cast<D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_], l[d.a4_], l[d.a5_], l[d.a6_], l[d.a7_], l[d.a8_], l[d.a9_]);
        }

        template<typename R, typename F, typename L>
        inline R operator()(type<R>, F &f, const L &l) const
        {
            const D &d = static_cast<const D&>(*this); d; //used C4189
            return f(l[d.a1_], l[d.a2_], l[d.a3_], l[d.a4_], l[d.a5_], l[d.a6_], l[d.a7_], l[d.a8_], l[d.a9_]);
        }
    };

    template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
    struct list9 : list9b<list9<A1, A2, A3, A4, A5, A6, A7, A8, A9>, A1, A2, A3, A4, A5, A6, A7, A8>
    {
        typedef list9b<list9<A1, A2, A3, A4, A5, A6, A7, A8, A9>, A1, A2, A3, A4, A5, A6, A7, A8> base;
        typedef typename param_traits<A9>::type P9;
        using base::operator[];

        list9(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, typename base::P5 p5, typename base::P6 p6, typename base::P7 p7, typename base::P8 p8, P9 p9) : base(p1, p2, p3, p4, p5, p6, p7, p8), a9_(p9) {}

        inline P9 operator[](Argc<9> (*)()) const { return a9_; }
        inline P9 operator[](Argc<9>) const { return a9_;}

        A9 a9_;
    };

    template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, int I>
    struct list9<A1, A2, A3, A4, A5, A6, A7, A8, Argc<I>(*)()> : list9b<list9<A1, A2, A3, A4, A5, A6, A7, A8, Argc<I>(*)()>, A1, A2, A3, A4, A5, A6, A7, A8>
    {
        typedef list9b<list9<A1, A2, A3, A4, A5, A6, A7, A8, Argc<I>(*)()>, A1, A2, A3, A4, A5, A6, A7, A8> base;
        typedef typename param_traits<Argc<I>(*)()>::type P9;
        using base::operator[];

        list9(typename base::P1 p1, typename base::P2 p2, typename base::P3 p3, typename base::P4 p4, typename base::P5 p5, typename base::P6 p6, typename base::P7 p7, typename base::P8 p8, P9) : base(p1, p2, p3, p4, p5, p6, p7, p8) {}

        static Argc<I> a9_() {  return Argc<I>(); }
    };

    template<typename R>
    bind_t<R, R (*)(), list0> bind(R (*f)())
    {
        typedef R (*F)();
        typedef list0 L;
        return bind_t<R, F, L>(f, L());
    }

    template<typename R, typename P1, typename A1>
    bind_t<R, R (*)(P1), list1<A1> > bind(R (*f)(P1), A1 a1)
    {
        typedef R (*F)(P1);
        typedef list1<A1> L;
        return bind_t<R, F, list1<A1> >(f, L(a1));
    }

    template<typename R, typename P1, typename P2, typename A1, typename A2>
    bind_t<R, R (*)(P1, P2), list2<A1, A2> > bind(R (*f)(P1, P2), A1 a1, A2 a2)
    {
        typedef R (*F)(P1, P2);
        typedef list2<A1, A2> L;
        return bind_t<R, F, L>(f, L(a1, a2));
    }

    template<typename R, typename P1, typename P2, typename P3, typename A1, typename A2, typename A3>
    bind_t<R, R (*)(P1, P2, P3), list3<A1, A2, A3> > bind(R (*f)(P1, P2, P3), A1 a1, A2 a2, A3 a3)
    {
        typedef R (*F)(P1, P2, P3);
        typedef list3<A1, A2, A3> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3));
    }

    template<typename R, typename P1, typename P2, typename P3, typename P4, typename A1, typename A2, typename A3, typename A4>
    bind_t<R, R (*)(P1, P2, P3, P4), list4<A1, A2, P3, A4> > bind(R (*f)(P1, P2, P3, P4), A1 a1, A2 a2, A3 a3, A4 a4)
    {
        typedef R (*F)(P1, P2, P3, P4);
        typedef list4<A1, A2, A3, A4> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3, a4));
    }

    template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename A1, typename A2, typename A3, typename A4, typename A5>
    bind_t<R, R (*)(P1, P2, P3, P4, P5), list5<A1, A2, A3, A4, A5> > bind(R (*f)(P1, P2, P3, P4, P5), A1 a1, A2 a2, A3 a3, A4 a4, A5 a5)
    {
        typedef R (*F)(P1, P2, P3, P4, P5);
        typedef list5<A1, A2, A3, A4, A5> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3, a4, a5));
    }

    template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
    bind_t<R, R (*)(P1, P2, P3, P4, P5, P6), list6<A1, A2, A3, A4, A5, A6> > bind(R (*f)(P1, P2, P3, P4, P5, P6), A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6)
    {
        typedef R (*F)(P1, P2, P3, P4, P5, P6);
        typedef list6<A1, A2, A3, A4, A5, A6> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3, a4, a5, a6));
    }

    template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
    bind_t<R, R (*)(P1, P2, P3, P4, P5, P6, P7), list7<A1, A2, A3, A4, A5, A6, A7> > bind(R (*f)(P1, P2, P3, P4, P5, P6, P7), A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7)
    {
        typedef R (*F)(P1, P2, P3, P4, P5, P6, P7);
        typedef list7<A1, A2, A3, A4, A5, A6, A7> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3, a4, a5, a6, a7));
    }
    template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
    bind_t<R, R (*)(P1, P2, P3, P4, P5, P6, P7, P8), list8<A1, A2, A3, A4, A5, A6, A7, A8> > bind(R (*f)(P1, P2, P3, P4, P5, P6, P7, P8), A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8)
    {
        typedef R (*F)(P1, P2, P3, P4, P5, P6, P7, P8);
        typedef list8<A1, A2, A3, A4, A5, A6, A7, A8> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3, a4, a5, a6, a7, a8));
    }

    template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
    bind_t<R, R (*)(P1, P2, P3, P4, P5, P6, P7, P8, P9), list9<A1, A2, A3, A4, A5, A6, A7, A8, A9> > bind(R (*f)(P1, P2, P3, P4, P5, P6, P7, P8, P9), A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9)
    {
        typedef R (*F)(P1, P2, P3, P4, P5, P6, P7, P8, P9);
        typedef list9<A1, A2, A3, A4, A5, A6, A7, A8, A9> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3, a4, a5, a6, a7, a8, a9));
    }

    template<typename F>
	bind_t<type<F>, F, list0> bind(F f)
    {
        typedef list0 L;
        return bind_t<type<F>, F, L>(f, L());
    }

    template<typename R, typename F>
    bind_t<R, F, list0> bind(const type<R>&, F f)
    {
        typedef list0 L;
        return bind_t<R, F, L>(f, L());
    }

    template<typename F, typename A1>
	bind_t<type<F>, F, list1<A1> > bind(F f, A1 a1)
    {
        typedef list1<A1> L;
        return bind_t<type<F>, F, L>(f, L(a1));
    }

    template<typename R, typename F, typename A1>
    bind_t<R, F, list1<A1> > bind(const type<R>&, F f, A1 a1)
	{
		typedef list1<A1> L;
        return bind_t<R, F, L>(f, L(a1));
    }

    template<typename F, typename A1, typename A2>
    bind_t<type<F>, F, list2<A1, A2> > bind(F f, A1 a1, A2 a2)
    {
        typedef list2<A1, A2> L;
        return bind_t<type<F>, F, L>(f, L(a1, a2));
    }

    template<typename R, typename F, typename A1, typename A2>
    bind_t<R, F, list2<A1, A2> > bind(const type<R>&, F f, A1 a1, A2 a2)
    {
        typedef list2<A1, A2> L;
        return bind_t<R, F, L>(f, L(a1, a2));
    }

    template<typename F, typename A1, typename A2, typename A3>
    bind_t<type<F>, F, list3<A1, A2, A3> > bind(F f, A1 a1, A2 a2, A3 a3)
    {
        typedef list3<A1, A2, A3> L;
        return bind_t<type<F>, F, L>(f, L(a1, a2, a3));
    }

    template<typename R, typename F, typename A1, typename A2, typename A3>
    bind_t<R, F, list3<A1, A2, A3> > bind(const type<R>&, F f, A1 a1, A2 a2, A3 a3)
    {
        typedef list3<A1, A2, A3> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3));
    }

    template<typename F, typename A1, typename A2, typename A3, typename A4>
    bind_t<type<F>, F, list4<A1, A2, A3, A4> > bind(F f, A1 a1, A2 a2, A3 a3, A4 a4)
    {
        typedef list4<A1, A2, A3, A4> L;
        return bind_t<type<F>, F, L>(f, L(a1, a2, a3, a4));
    }

    template<typename R, typename F, typename A1, typename A2, typename A3, typename A4>
    bind_t<R, F, list4<A1, A2, A3, A4> > bind(const type<R>&, F f, A1 a1, A2 a2, A3 a3, A4 a4)
    {
        typedef list4<A1, A2, A3, A4> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3, a4));
    }

    template<typename F, typename A1, typename A2, typename A3, typename A4, typename A5>
    bind_t<type<F>, F, list5<A1, A2, A3, A4, A5> > bind(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5)
    {
        typedef list5<A1, A2, A3, A4, A5> L;
        return bind_t<type<F>, F, L>(f, L(a1, a2, a3, a4, a5));
    }

    template<typename R, typename F, typename A1, typename A2, typename A3, typename A4, typename A5>
    bind_t<R, F, list5<A1, A2, A3, A4, A5> > bind(const type<R>&, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5)
    {
        typedef list5<A1, A2, A3, A4, A5> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3, a4, a5));
    }

    template<typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
    bind_t<type<F>, F, list6<A1, A2, A3, A4, A5, A6> > bind(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6)
    {
        typedef list6<A1, A2, A3, A4, A5, A6> L;
        return bind_t<type<F>, F, L>(f, L(a1, a2, a3, a4, a5, a6));
    }

    template<typename R, typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
    bind_t<R, F, list6<A1, A2, A3, A4, A5, A6> > bind(const type<R>&, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6)
    {
        typedef list6<A1, A2, A3, A4, A5, A6> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3, a4, a5, a6));
    }

    template<typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
    bind_t<type<F>, F, list7<A1, A2, A3, A4, A5, A6, A7> > bind(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7)
    {
        typedef list7<A1, A2, A3, A4, A5, A6, A7> L;
        return bind_t<type<F>, F, L>(f, L(a1, a2, a3, a4, a5, a6, a7));
    }

    template<typename R, typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
    bind_t<R, F, list7<A1, A2, A3, A4, A5, A6, A7> > bind(const type<R>&, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7)
    {
        typedef list7<A1, A2, A3, A4, A5, A6, A7> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3, a4, a5, a6, a7));
    }

    template<typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
    bind_t<type<F>, F, list8<A1, A2, A3, A4, A5, A6, A7, A8> > bind(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8)
    {
        typedef list8<A1, A2, A3, A4, A5, A6, A7, A8> L;
        return bind_t<type<F>, F, L>(f, L(a1, a2, a3, a4, a5, a6, a7, a8));
    }

    template<typename R, typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
    bind_t<R, F, list8<A1, A2, A3, A4, A5, A6, A7, A8> > bind(const type<R>&, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8)
    {
        typedef list8<A1, A2, A3, A4, A5, A6, A7, A8> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3, a4, a5, a6, a7, a8));
    }

    template<typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	bind_t<type<F>, F, list9<A1, A2, A3, A4, A5, A6, A7, A8, A9> > bind(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9)
    {
        typedef list9<A1, A2, A3, A4, A5, A6, A7, A8, A9> L;
        return bind_t<type<F>, F, L>(f, L(a1, a2, a3, a4, a5, a6, a7, a8, a9));
    }

    template<typename R, typename F, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
    bind_t<R, F, list9<A1, A2, A3, A4, A5, A6, A7, A8, A9> > bind(const type<R>&, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9)
    {
        typedef list9<A1, A2, A3, A4, A5, A6, A7, A8, A9> L;
        return bind_t<R, F, L>(f, L(a1, a2, a3, a4, a5, a6, a7, a8, a9));
    }

    template<typename R, typename C, typename C1>
    bind_t<R, f_cplus_0<R, C, R (C::*)()>, list1<C1> > bind(R (C::*f)(), C1 c1)
    {
        typedef f_cplus_0<R, C, R (C::*)()> F;
        typedef list1<C1> L;
        return bind_t<R, F, L>(F(f), L(c1));
    }

    template<typename R, typename C, typename C1>
    bind_t<R, f_cplus_0<R, C, R (C::*)() const>, list1<C1> > bind(R (C::*f)() const, C1 c1)
    {
        typedef f_cplus_0<R, C, R (C::*)() const> F;
        typedef list1<C1> L;
        return bind_t<R, F, L>(F(f), L(c1));
    }

    template<typename R, typename C, typename A1, typename C1, typename P1>
    bind_t<R, f_cplus_1<R, C, R (C::*)(A1)>, list2<C1, P1> > bind(R (C::*f)(A1), C1 c1, P1 p2)
    {
        typedef f_cplus_1<R, C, R (C::*)(A1)> F;
        typedef list2<C1, P1> L;
        return bind_t<R, F, L>(F(f), L(c1, p2));
    }

    template<typename R, typename C, typename A1, typename C1, typename P1>
    bind_t<R, f_cplus_1<R, C, R (C::*)(A1) const>, list2<C1, P1> > bind(R (C::*f)(A1) const, C1 c1, P1 p1)
    {
        typedef f_cplus_1<R, C, R (C::*)(A1) const> F;
        typedef list2<C1, P1> L;
        return bind_t<R, F, L>(F(f), L(c1, p1));
    }

    template<typename R, typename C, typename A1, typename A2, typename C1, typename P1, typename P2>
    bind_t<R, f_cplus_2<R, C, R (C::*)(A1,A2)>, list3<C1, P1, P2> > bind(R (C::*f)(A1,A2), C1 c1, P1 p1, P2 p2)
    {
        typedef f_cplus_2<R, C, R (C::*)(A1,A2)> F;
        typedef list3<C1, P1, P2> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2));
    }

    template<typename R, typename C, typename A1, typename A2, typename C1, typename P1, typename P2>
    bind_t<R, f_cplus_2<R, C, R (C::*)(A1,A2) const>, list3<C1, P1, P2> > bind(R (C::*f)(A1,A2) const, C1 c1, P1 p1, P2 p2)
    {
        typedef f_cplus_2<R, C, R (C::*)(A1,A2) const> F;
        typedef list3<C1, P1, P2> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2));
    }

    template<typename R, typename C, typename A1, typename A2, typename A3, typename C1, typename P1, typename P2, typename P3>
    bind_t<R, f_cplus_3<R, C, R (C::*)(A1,A2,A3)>, list4<C1, P1, P2, P3> > bind(R (C::*f)(A1,A2,A3), C1 c1, P1 p1, P2 p2, P3 p3)
    {
        typedef f_cplus_3<R, C, R (C::*)(A1,A2,A3)> F;
        typedef list4<C1, P1, P2, P3> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2, p3));
    }

    template<typename R, typename C, typename A1, typename A2, typename A3, typename C1, typename P1, typename P2, typename P3>
    bind_t<R, f_cplus_3<R, C, R (C::*)(A1,A2,A3) const>, list4<C1, P1, P2, P3> > bind(R (C::*f)(A1,A2,A3) const, C1 c1, P1 p1, P2 p2, P3 p3)
    {
        typedef f_cplus_3<R, C, R (C::*)(A1,A2,A3) const> F;
        typedef list4<C1, P1, P2, P3> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2, p3));
    }

    template<typename R, typename C, typename A1, typename A2, typename A3, typename A4, typename C1, typename P1, typename P2, typename P3, typename P4>
    bind_t<R, f_cplus_4<R, C, R (C::*)(A1,A2,A3,A4)>, list5<C1, P1, P2, P3, P4> > bind(R (C::*f)(A1,A2,A3,A4), C1 c1, P1 p1, P2 p2, P3 p3, P4 p4)
    {
        typedef f_cplus_4<R, C, R (C::*)(A1,A2,A3,A4)> F;
        typedef list5<C1, P1, P2, P3, P4> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2, p3, p4));
    }

    template<typename R, typename C, typename A1, typename A2, typename A3, typename A4, typename C1, typename P1, typename P2, typename P3, typename P4>
    bind_t<R, f_cplus_4<R, C, R (C::*)(A1,A2,A3,A4) const>, list5<C1, P1, P2, P3, P4> > bind(R (C::*f)(A1,A2,A3,A4) const, C1 c1, P1 p1, P2 p2, P3 p3, P4 p4)
    {
        typedef f_cplus_4<R, C, R (C::*)(A1,A2,A3,A4) const> F;
        typedef list5<C1, P1, P2, P3, P4> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2, p3, p4));
    }

    template<typename R, typename C, typename A1, typename A2, typename A3, typename A4, typename A5, typename C1, typename P1, typename P2, typename P3, typename P4, typename P5>
    bind_t<R, f_cplus_5<R, C, R (C::*)(A1,A2,A3,A4,A5)>, list6<C1, P1, P2, P3, P4, P5> > bind(R (C::*f)(A1,A2,A3,A4,A5), C1 c1, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
    {
        typedef f_cplus_5<R, C, R (C::*)(A1,A2,A3,A4,A5)> F;
        typedef list6<C1, P1, P2, P3, P4, P5> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2, p3, p4, p5));
    }

    template<typename R, typename C, typename A1, typename A2, typename A3, typename A4, typename A5, typename C1, typename P1, typename P2, typename P3, typename P4, typename P5>
    bind_t<R, f_cplus_5<R, C, R (C::*)(A1,A2,A3,A4,A5) const>, list6<C1, P1, P2, P3, P4, P5> > bind(R (C::*f)(A1,A2,A3,A4,A5) const, C1 c1, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
    {
        typedef f_cplus_5<R, C, R (C::*)(A1,A2,A3,A4,A5) const> F;
        typedef list6<C1, P1, P2, P3, P4, P5> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2, p3, p4, p5));
    }

    template<typename R, typename C, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename C1, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    bind_t<R, f_cplus_6<R, C, R (C::*)(A1,A2,A3,A4,A5,A6)>, list7<C1, P1, P2, P3, P4, P5, P6> > bind(R (C::*f)(A1,A2,A3,A4,A5,A6), C1 c1, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
    {
        typedef f_cplus_6<R, C, R (C::*)(A1,A2,A3,A4,A5,A6)> F;
        typedef list7<C1, P1, P2, P3, P4, P5, P6> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2, p3, p4, p5, p6));
    }

    template<typename R, typename C, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename C1, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    bind_t<R, f_cplus_6<R, C, R (C::*)(A1,A2,A3,A4,A5,A6) const>, list7<C1, P1, P2, P3, P4, P5, P6> > bind(R (C::*f)(A1,A2,A3,A4,A5,A6) const, C1 c1, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
    {
        typedef f_cplus_6<R, C, R (C::*)(A1,A2,A3,A4,A5,A6) const> F;
        typedef list7<C1, P1, P2, P3, P4, P5, P6> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2, p3, p4, p5, p6));
    }

    template<typename R, typename C, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename C1, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    bind_t<R, f_cplus_7<R, C, R (C::*)(A1,A2,A3,A4,A5,A6,A7)>, list8<C1, P1, P2, P3, P4, P5, P6, P7> > bind(R (C::*f)(A1,A2,A3,A4,A5,A6,A7), C1 c1, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
    {
        typedef f_cplus_7<R, C, R (C::*)(A1,A2,A3,A4,A5,A6,A7)> F;
        typedef list8<C1, P1, P2, P3, P4, P5, P6, P7> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2, p3, p4, p5, p6, p7));
    }

    template<typename R, typename C, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename C1, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
    bind_t<R, f_cplus_7<R, C, R (C::*)(A1,A2,A3,A4,A5,A6,A7) const>, list8<C1, P1, P2, P3, P4, P5, P6, P7> > bind(R (C::*f)(A1,A2,A3,A4,A5,A6,A7) const, C1 c1, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
    {
        typedef f_cplus_7<R, C, R (C::*)(A1,A2,A3,A4,A5,A6,A7) const> F;
        typedef list8<C1, P1, P2, P3, P4, P5, P6, P7> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2, p3, p4, p5, p6, p7));
    }

    template<typename R, typename C, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename C1, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    bind_t<R, f_cplus_8<R, C, R (C::*)(A1,A2,A3,A4,A5,A6,A7,A8)>, list9<C1, P1, P2, P3, P4, P5, P6, P7, P8> > bind(R (C::*f)(A1,A2,A3,A4,A5,A6,A7,A8), C1 c1, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8)
    {
        typedef f_cplus_8<R, C, R (C::*)(A1,A2,A3,A4,A5,A6,A7,A8)> F;
        typedef list9<C1, P1, P2, P3, P4, P5, P6, P7, P8> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2, p3, p4, p5, p6, p7, p8));
    }

    template<typename R, typename C, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename C1, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
    bind_t<R, f_cplus_8<R, C, R (C::*)(A1,A2,A3,A4,A5,A6,A7,A8) const>, list9<C1, P1, P2, P3, P4, P5, P6, P7, P8> > bind(R (C::*f)(A1,A2,A3,A4,A5,A6,A7,A8) const, C1 c1, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8)
    {
        typedef f_cplus_8<R, C, R (C::*)(A1,A2,A3,A4,A5,A6,A7,A8) const> F;
        typedef list9<C1, P1, P2, P3, P4, P5, P6, P7, P8> L;
        return bind_t<R, F, L>(F(f), L(c1, p1, p2, p3, p4, p5, p6, p7, p8));
    }

    template<typename R, typename F, typename L> struct bind_t
    {
    public:
        typedef typename result_traits<R>::type result_type;

    public:
        bind_t(const F &f, const L &l) : f_(f), l_(l) {}

        template<typename A>
        inline result_type eval(A &a)
        {
            return l_(type<result_type>(), f_, a);
        }

        template<typename A>
        inline result_type eval(A &a) const
        {
            return l_(type<result_type>(), f_,  a);
        }

        inline result_type operator()()
        {
            typedef list0 ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll()));
        }

        inline result_type operator()() const
        {
            typedef list0 ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll()));
        }

        template<typename P1>
        inline result_type operator()(P1 &p1)
        {
            typedef list1<P1&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1)));
        }

        template<typename P1>
        inline result_type operator()(P1 &p1) const
        {
            typedef list1<P1&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1)));
        }

        template<typename P1>
        inline result_type operator()(const P1 &p1)
        {
            typedef list1<const P1&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1)));
        }

        template<typename P1>
        inline result_type operator()(const P1 &p1) const
        {
            typedef list1<const P1&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1)));
        }

        template<typename P1, typename P2>
        inline result_type operator()(P1 &p1, P2 &p2)
        {
            typedef list2<P1&, P2&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2)));
        }

        template<typename P1, typename P2>
        inline result_type operator()(P1 &p1, P2 &p2) const
        {
            typedef list2<P1&, P2&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2)));
        }

        template<typename P1, typename P2>
        inline result_type operator()(const P1 &p1, P2 &p2)
        {
            typedef list2<const P1&, P2&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2)));
        }

        template<typename P1, typename P2>
        inline result_type operator()(const P1 &p1, P2 &p2) const
        {
            typedef list2<const P1&, P2&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2)));
        }

        template<typename P1, typename P2>
        inline result_type operator()(P1 &p1, const P2 &p2)
        {
            typedef list2<P1&, const P2&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2)));
        }

        template<typename P1, typename P2>
        inline result_type operator()(P1 &p1, const P2 &p2) const
        {
            typedef list2<P1&, const P2&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2)));
        }

        template<typename P1, typename P2>
        inline result_type operator()(const P1 &p1, const P2 &p2)
        {
            typedef list2<const P1&, const P2&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2)));
        }

        template<typename P1, typename P2>
        inline result_type operator()(const P1 &p1, const P2 &p2) const
        {
            typedef list2<const P1&, const P2&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2)));
        }

        template<typename P1, typename P2, typename P3>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3)
        {
            typedef list3<P1&, P2&, P3&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3)));
        }

        template<typename P1, typename P2, typename P3>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3) const
        {
            typedef list3<P1&, P2&, P3&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3)));
        }

        template<typename P1, typename P2, typename P3>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3)
        {
            typedef list3<const P1&, const P2&, const P3&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3)));
        }

        template<typename P1, typename P2, typename P3>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3) const
        {
            typedef list3<const P1&, const P2&, const P3&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3)));
        }

        template<typename P1, typename P2, typename P3, typename P4>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3, P4 &p4)
        {
            typedef list4<P1&, P2&, P3&, P4&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4)));
        }

        template<typename P1, typename P2, typename P3, typename P4>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3, P4 &p4) const
        {
            typedef list4<P1&, P2&, P3&, P4&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4)));
        }

        template<typename P1, typename P2, typename P3, typename P4>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
        {
            typedef list4<const P1&, const P2&, const P3&, const P4&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4)));
        }

        template<typename P1, typename P2, typename P3, typename P4>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4) const
        {
            typedef list4<const P1&, const P2&, const P3&, const P4&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3, P4 &p4, P5 &p5)
        {
            typedef list5<P1&, P2&, P3&, P4&, P5&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3, P4 &p4, P5 &p5) const
        {
            typedef list5<P1&, P2&, P3&, P4&, P5&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5)
        {
            typedef list5<const P1&, const P2&, const P3&, const P4&, const P5&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5) const
        {
            typedef list5<const P1&, const P2&, const P3&, const P4&, const P5&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3, P4 &p4, P5 &p5, P6 &p6)
        {
            typedef list6<P1&, P2&, P3&, P4&, P5&, P6&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3, P4 &p4, P5 &p5, P6 &p6) const
        {
            typedef list6<P1&, P2&, P3&, P4&, P5&, P6&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6)
        {
            typedef list6<const P1&, const P2&, const P3&, const P4&, const P5&, const P6&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(list_av<ll>(ll(p1, p2, p3, p4, p5, p6))));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6) const
        {
            typedef list6<const P1&, const P2&, const P3&, const P4&, const P5&, const P6&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3, P4 &p4, P5 &p5, P6 &p6, P7 &p7)
        {
            typedef list7<P1&, P2&, P3&, P4&, P5&, P6&, P7&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6, p7)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3, P4 &p4, P5 &p5, P6 &p6, P7 &p7) const
        {
            typedef list7<P1&, P2&, P3&, P4&, P5&, P6&, P7&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6, p7)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7)
        {
            typedef list7<const P1&, const P2&, const P3&, const P4&, const P5&, const P6&, const P7&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6, p7)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7) const
        {
            typedef list7<const P1&, const P2&, const P3&, const P4&, const P5&, const P6&, const P7&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6, p7)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3, P4 &p4, P5 &p5, P6 &p6, P7 &p7, P8 &p8)
        {
            typedef list8<P1&, P2&, P3&, P4&, P5&, P6&, P7&, P8&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6, p7, p8)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3, P4 &p4, P5 &p5, P6 &p6, P7 &p7, P8 &p8) const
        {
            typedef list8<P1&, P2&, P3&, P4&, P5&, P6&, P7&, P8&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6, p7, p8)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8)
        {
            typedef list8<const P1&, const P2&, const P3&, const P4&, const P5&, const P6&, const P7&, const P8&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6, p7, p8)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8) const
        {
            typedef list8<const P1&, const P2&, const P3&, const P4&, const P5&, const P6&, const P7&, const P8&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6, p7, p8)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3, P4 &p4, P5 &p5, P6 &p6, P7 &p7, P8 &p8, P9 &p9)
        {
            typedef list9<P1&, P2&, P3&, P4&, P5&, P6&, P7&, P8&, P9&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6, p7, p8, p9)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        inline result_type operator()(P1 &p1, P2 &p2, P3 &p3, P4 &p4, P5 &p5, P6 &p6, P7 &p7, P8 &p8, P9 &p9) const
        {
            typedef list9<P1&, P2&, P3&, P4&, P5&, P6&, P7&, P8&, P9&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6, p7, p8, p9)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9)
        {
            typedef list9<const P1&, const P2&, const P3&, const P4&, const P5&, const P6&, const P7&, const P8&, const P9&> ll;
            return l_(type<result_type>(), f_, list_av<ll>(ll(p1, p2, p3, p4, p5, p6, p7, p8, p9)));
        }

        template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
        inline result_type operator()(const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5, const P6 &p6, const P7 &p7, const P8 &p8, const P9 &p9) const
        {
            typedef list9<const P1&, const P2&, const P3&, const P4&, const P5&, const P6&, const P7&, const P8&, const P9&> ll;
            return l_(type<result_type>(), f_,  list_av<ll>(ll(p1, p2, p3, p4, p5, p6, p7, p8, p9)));
        }

    private:
        F f_;
        L l_;
    };

    template<typename D>
    struct mem_list_b : list0
    {
        typedef list0 base;

        template<typename R, typename O, typename L>
        inline R operator()(type<R>, const O &o, const L &l)
        {
            D &d = static_cast<D&>(*this); d;  //used C4189
            return o(l[d.a_]);
        }

        template<typename R, typename O, typename L>
        inline R operator()(type<R>, const O &o, const L &l) const
        {
            const D &d = static_cast<const D&>(*this); d;  //used C4189
            return o(l[d.a_]);
        }
    };

    template<typename A>
    struct mem_list : mem_list_b<mem_list<A> >
    {
        typedef mem_list_b<mem_list<A> > base;
        typedef typename param_traits<A>::type P;

        using base::operator[];

        explicit mem_list(P p) : a_(p) {}
        inline P operator[](Argc<1>(*)()) const { return a_;}
        inline P operator[](Argc<1>) const { return a_;}

        A a_;
    };

    template<int I>
    struct mem_list<Argc<I>(*)()> : mem_list_b<mem_list<Argc<I>(*)()> >
    {
        typedef mem_list_b<mem_list<Argc<I>(*)()> > base;
        typedef typename param_traits<Argc<I>(*)()>::type P;

        using base::operator[];

        explicit mem_list(P){}
        static Argc<I> a_() {return Argc<I>();}
    };

    template<typename lt>
    struct mem_list_av : lt
    {
        typedef lt base;
        mem_list_av(const lt &ll) : base(ll) {}

        using base::operator[];

        template<typename R, typename C, typename L>
        inline R operator[](const mem_bind_t<R, C, L> &b) const 
        { 
            return b.eval(*this);
        }

        template<typename R, typename C, typename L>
        inline R operator[](mem_bind_t<R, C, L> &b) const 
        { 
            return b.eval(*this);
        }
    };

    template<typename R, typename M> struct mem_object_t
    {
        typedef typename result_traits<R>::type result_type;

        mem_object_t(const M &m) : m_(m){}

        template<typename T> 
        inline result_type operator()(T &t) const { return t.*m_; }

        template<typename T> 
        inline const result_type operator()(const T &t) const { return t.*m_; }

        template<typename T> 
        inline result_type operator()(T *t) const { return t->*m_; }

        template<typename T> 
        inline const result_type operator()(const T *t) const { return t->*m_; }

        const M &m_;
    };

    template<typename R, typename C, typename L> struct mem_bind_t
    {
    public:
        typedef typename result_traits<R>::type result_type;
        typedef R C:: *M;
        typedef mem_object_t<result_type, M> O;

        mem_bind_t(M m, const L &l) : m_(m), l_(l){}

        template<typename A> inline result_type eval(A &a)
        {
            return l_(type<result_type>(), O(m_), a);
        }

        template<typename A> inline result_type eval(A &a) const
        {
            return l_(type<result_type>(), O(m_),  a);
        }

        inline result_type operator()()
        {
            typedef list0 ll;
            typedef list_av<ll> ll_av;
            typedef mem_list_av<ll_av> m_ll_av;
            return l_(type<result_type>(), O(m_), m_ll_av(ll_av(ll())));
        }

        inline result_type operator()() const
        {
            typedef list0 ll;
            typedef list_av<ll> ll_av;
            typedef mem_list_av<ll_av> m_ll_av;
            return l_(type<result_type>(), O(m_), m_ll_av(ll_av(ll())));
        }

        template<typename P> inline result_type operator()(P &p)
        {
            typedef mem_list<P&> ll;
            typedef list_av<ll> ll_av;
            typedef mem_list_av<ll_av> m_ll_av;
            return l_(type<result_type>(), O(m_), m_ll_av(ll_av(ll(p))));
        }

        template<typename P> inline result_type operator()(P &p) const
        {
            typedef mem_list<P&> ll;
            typedef list_av<ll> ll_av;
            typedef mem_list_av<ll_av> m_ll_av;
            return l_(type<result_type>(), O(m_), m_ll_av(ll_av(ll(p))));
        }

        template<typename P> inline result_type operator()(const P &p)
        {
            typedef mem_list<const P&> ll;
            typedef list_av<ll> ll_av;
            typedef mem_list_av<ll_av> m_ll_av;
            return l_(type<result_type>(), O(m_), m_ll_av(ll_av(ll(p))));
        }

        template<typename P> inline result_type operator()(const P &p) const
        {
            typedef mem_list<const P&> ll;
            typedef list_av<ll> ll_av;
            typedef mem_list_av<ll_av> m_ll_av;
            return l_(type<result_type>(), O(m_), m_ll_av(ll_av(ll(p))));
        }

    private:
        M m_;
        L l_;
    };

    template<typename R, typename C>
    mem_bind_t<R, C, mem_list_av<list0> > bind(R C::*p)
    {
        typedef list0 L;
        return mem_bind_t<R, C, mem_list_av<L> >(p, mem_list_av<L>(L()));
    }

    template<typename R, typename C, typename A>
    mem_bind_t<R, C, mem_list_av<mem_list<A> > > bind(R C::*p, A a)
    {
        typedef mem_list<A> L;
        return mem_bind_t<R, C, mem_list_av<L> >(p, mem_list_av<L>(L(a)));
    }

} // namespace bi

namespace
{
    static inline bi::Argc<1> _1() { return bi::Argc<1>(); }
    static inline bi::Argc<2> _2() { return bi::Argc<2>(); }
    static inline bi::Argc<3> _3() { return bi::Argc<3>(); }
    static inline bi::Argc<4> _4() { return bi::Argc<4>(); }
    static inline bi::Argc<5> _5() { return bi::Argc<5>(); }
    static inline bi::Argc<6> _6() { return bi::Argc<6>(); }
    static inline bi::Argc<7> _7() { return bi::Argc<7>(); }
    static inline bi::Argc<8> _8() { return bi::Argc<8>(); }
    static inline bi::Argc<9> _9() { return bi::Argc<9>(); }

} // unnamed namespace

#ifdef _MSC_VER
# pragma warning(default: 4512) // assignment operator could not be generated
# pragma warning(pop)
#endif

#endif // bind_h__
