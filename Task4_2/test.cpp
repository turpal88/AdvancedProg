#include "Task4_2.cpp"
#include "Catch2/catch_test_macros.hpp"
#include "Catch2/catch_session.hpp"


TEST_CASE("tests_with_list", "[list_tests]") {
	List list;
	list.PushBack(15);
	list.PushBack(30);
	list.PushFront(45);
	list.PushFront(55);
	SECTION("Push-Pop methods") {
		INFO("Result of PopBack is not 30");
		CHECK(list.PopBack() == 30);
		INFO("Result of PopBack is not 15");
		CHECK(list.PopBack() == 15);
		INFO("Result of PopBack is not 45");
		CHECK(list.PopFront() == 55);
		INFO("Result of PopBack is not 55");
		CHECK(list.PopFront() == 45);
		
	}
	

	
}

int main() {

	return Catch::Session().run();
}


