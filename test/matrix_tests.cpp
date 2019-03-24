#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "baseTestModule"
#include <boost/test/unit_test.hpp>
#include <Matrix.hpp>

BOOST_AUTO_TEST_CASE( test_matrix_dim )
{ 
  BOOST_CHECK_EQUAL( 2,2 );
}
