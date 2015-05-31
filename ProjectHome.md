boost中有一个bind库， 可以说是一个最为实用的tools了， 但是它与boost结合的有些紧密，而且其中的一些功能并不是很常用，就算将它bcp出独立的库也是一个不小的负担。如果在你的项目中不打算有boost库的痕迹但是又想使用bind的强大功能，那就来看看它吧。

一个一个超小型的bind库， 它实现了大部分boost::bind的功能， 只是将名字空间由boost 变换为 bi 。如果使用了一般的使用中通常可以将

boost::bind(my\_fun(), _1,_2)(234, "lskdf"); 形式替换为 bi::bind(my\_fun(), _1,_2)(234, "lskdjfld"),

既可完成编译，如果使用了名字空间，那就只需要将 using namespace boost 替换为 using namespafce bi 即可完成转化。

但是....

bi::bind没有打算支持boost库， 如果在你的项目中使用了其它的boost‘tools，那你就不需要它了（或许也可以拿来研究研究），既然使用了boost,就不在乎在使用boost::bind了，所以boost::bind中涉及到与其它boost库的有交集的功能bi::bind库都没有支持。

但是 它确自然支持 boost::shared\_ptr， 这个我也没有料想到。

bi::bind借鉴了boost::bind的一些思想，有些代码甚至是直接从bind.hpp中复制过来的，但它在牺牲一些扩展性和多平台支持性的后果下， 同样的代码比boost::bind中有40%的效率提升 。