set(BOOST_REQD_SUBMODULES
        "tools/cmake;"
        "libs/assert;libs/exception;libs/throw_exception;libs/static_assert;"
        "libs/bind;libs/function_types;libs/function;"
        "libs/chrono;libs/date_time;"
        "libs/concept_check;"
        "libs/config;libs/container;libs/container_hash;"
        "libs/iterator;libs/utility;libs/type_traits;libs/algorithm;;libs/conversion;libs/numeric/conversion;libs/regex;libs/unordered;libs/tokenizer;libs/move;libs/ratio;libs/lexical_cast;"
        "libs/tuple;libs/variant2;libs/typeof;libs/detail;libs/array;libs/type_index;libs/range;libs/optional;libs/smart_ptr;libs/integer;libs/rational;"
        "libs/intrusive;libs/io;"
        "libs/core;libs/align;libs/predef;libs/preprocessor;libs/system;libs/winapi;libs/atomic;"
        "libs/mpl;libs/fusion;libs/mp11;"
        "libs/thread"
        "libs/coroutine"
        "libs/context"
        "libs/pool"
        "libs/asio"
        "libs/bind"
        "libs/serialization"
        "libs/spirit"
        "libs/endian"
        "libs/proto"
        "libs/variant"
        "libs/phoenix"
        "libs/functional"
        "libs/lambda"
        "libs/describe"
        )

if (NOT boost_FOUND) # If there's none, fetch and build boost
  include(FetchContent)
  FetchContent_Declare(
          boost
          GIT_REPOSITORY "https://github.com/boostorg/boost.git"
          GIT_TAG master
          GIT_SUBMODULES ${BOOST_REQD_SUBMODULES}
          GIT_PROGRESS TRUE
          CONFIGURE_COMMAND ""
  )
  FetchContent_GetProperties(boost)
  if (NOT boost_POPULATED) # Have we downloaded boost yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(boost)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${boost_SOURCE_DIR} ${boost_BINARY_DIR})
  endif()
endif()
#[[
set(BOOST_REQD_SUBMODULES
    "tools/cmake;"
    "libs/assert;libs/exception;libs/throw_exception;libs/static_assert;"
    "libs/bind;libs/function_types;libs/function;"
    "libs/chrono;libs/date_time;"
    "libs/concept_check;"
    "libs/config;libs/container;libs/container_hash;"
    "libs/iterator;libs/utility;libs/type_traits;libs/algorithm;;libs/conversion;libs/numeric/conversion;libs/regex;libs/unordered;libs/tokenizer;libs/move;libs/ratio;libs/lexical_cast;"
    "libs/tuple;libs/variant2;libs/typeof;libs/detail;libs/array;libs/type_index;libs/range;libs/optional;libs/smart_ptr;libs/integer;libs/rational;"
    "libs/intrusive;libs/io;"
    "libs/core;libs/align;libs/predef;libs/preprocessor;libs/system;libs/winapi;libs/atomic;"
    "libs/mpl;libs/fusion;libs/mp11;"
    "libs/thread"
    "libs/coroutine"
    "libs/context"
    "libs/pool"
    "libs/asio"
    "libs/bind"
    "libs/serialization"
    "libs/spirit"
    "libs/endian"
    "libs/proto"
    "libs/variant"
    "libs/phoenix"
    "libs/functional"
    "libs/lambda"
)

if (NOT boost_FOUND) # If there's none, fetch and build boost
  include(FetchContent)
  FetchContent_Declare(
    boost
    GIT_REPOSITORY "https://github.com/boostorg/boost.git"
    GIT_TAG master
    GIT_SUBMODULES ${BOOST_REQD_SUBMODULES}
    GIT_PROGRESS TRUE
    CONFIGURE_COMMAND ""
  )
  FetchContent_GetProperties(boost)
  if (NOT boost_POPULATED) # Have we downloaded boost yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(boost)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${boost_SOURCE_DIR} ${boost_BINARY_DIR})
  endif()
endif()]]
