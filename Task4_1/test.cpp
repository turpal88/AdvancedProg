#include "Task4_1.cpp"
#include "Catch2/catch_test_macros.hpp"
#include "Catch2/catch_session.hpp"


void add_to_list(List& list) {

	

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) list.PushFront(i);
		else list.PushBack(i);
	}
	
}

void remove_from_list(List& list) {
for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) list.PopFront();
		
	}

}

TEST_CASE("tests_with_list", "[list_tests]") {
	List list;
	SECTION("Empty method") {

		CHECK(list.Empty() == true);
	}
	add_to_list(list);
	remove_from_list(list);
	
	SECTION("Size method") {
		INFO("Size of list is not equal 5");
		CHECK(list.Size() == 15);
	}
	SECTION("Clear method") {
		list.Clear();
		CHECK(list.Size() == 0);
	}
}

int main() {
	
	return Catch::Session().run();
}


