// Uncomment the next line to use precompiled headers
//#include "pch.h"
// uncomment the next line if you do not use precompiled headers
#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset( new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
// is the collection created
ASSERT_TRUE(collection);

// if empty, the size must be 0
ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
// is the collection empty?
ASSERT_TRUE(collection->empty());

// if empty, the size must be 0
ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
//TEST_F(CollectionTest, AlwaysFail)
//{
//FAIL();
//}

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // Is the collection empty
    ASSERT_TRUE(collection -> empty());
    // If empty, the size must be 0
    ASSERT_EQ(collection -> size(), 0);

    add_entries(1);

    // Is the collection still empty?
    ASSERT_FALSE(collection -> empty());
    // Ff not empty, what must the size be?
    ASSERT_EQ(collection -> size(), 1);
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    // Is the collection empty?
    ASSERT_TRUE(collection -> empty());
    // If empty, the size must be 0
    ASSERT_EQ(collection -> size(), 0);

    add_entries(5);

    // Is the collection still empty?
    ASSERT_FALSE(collection -> empty());
    // If not empty, what must the size be?
    ASSERT_EQ(collection -> size(), 5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, MaxSizeGreaterOrEqual)
{
    // Check 0
    // Is the collection empty?
    ASSERT_TRUE(collection -> empty());
    // Check collection size
    ASSERT_EQ(collection -> size(), 0);
    // Check Max Size
    ASSERT_GE(collection -> max_size(), collection->size());

    // Check 1
    add_entries(1);
    // is the collection empty?
    ASSERT_FALSE(collection -> empty());
    // Check collection size
    ASSERT_EQ(collection -> size(), 1);
    // Check Max Size
    ASSERT_GE(collection -> max_size(), collection->size());

    // Check 5
    add_entries(4);
    // is the collection empty?
    ASSERT_FALSE(collection -> empty());
    // Check collection size
    ASSERT_EQ(collection -> size(), 5);
    // Check Max Size
    ASSERT_GE(collection -> max_size(), collection->size());

    // Check 10
    add_entries(5);
    // is the collection empty?
    ASSERT_FALSE(collection -> empty());
    // Check collection size
    ASSERT_EQ(collection -> size(), 10);
    // Check Max Size
    ASSERT_GE(collection -> max_size(), collection->size());
}

// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, CapacityGreaterOrEqual)
{
    // Check 0
    // Is the collection empty?
    ASSERT_TRUE(collection -> empty());
    // Check collection size
    ASSERT_EQ(collection -> size(), 0);
    // Check capacity
    ASSERT_GE(collection -> capacity(), collection->size());

    // Check 1
    add_entries(1);
    // Is the collection empty?
    ASSERT_FALSE(collection -> empty());
    // Check collection size
    ASSERT_EQ(collection -> size(), 1);
    // Check capacity
    ASSERT_GE(collection -> capacity(), collection->size());

    // Check 5
    add_entries(4);
    // Is the collection empty?
    ASSERT_FALSE(collection -> empty());
    // Check collection size
    ASSERT_EQ(collection -> size(), 5);
    // Check capacity
    ASSERT_GE(collection -> capacity(), collection->size());

    // Check 10
    add_entries(5);
    // Is the collection empty?
    ASSERT_FALSE(collection -> empty());
    // Check collection size
    ASSERT_EQ(collection -> size(), 10);
    // Check capacity
    ASSERT_GE(collection -> capacity(), collection->size());
}

// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, ResizeIncreaseCollection)
{
    // Is the collection empty?
    ASSERT_TRUE(collection -> empty());
    // If empty, the size must be 0
    ASSERT_EQ(collection -> size(), 0);

    collection -> resize(5);

    // Is the collection still empty?
    ASSERT_FALSE(collection->empty());
    // If not empty, what must the size be?
    ASSERT_EQ(collection->size(), 5);
}

// TODO: Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, ResizeDecreaseCollection)
{
    add_entries(5);

    // Is collection empty
    ASSERT_FALSE(collection -> empty());
    // If not empty
    ASSERT_EQ(collection -> size(), 5);
    // Resize
    collection -> resize(1);
    // Is collection empty
    ASSERT_FALSE(collection -> empty());
    // If not empty
    ASSERT_EQ(collection -> size(), 1);
}

// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, ResizeDecreaseCollectionToZero)
{
    add_entries(5);

    // Is collection empty
    ASSERT_FALSE(collection -> empty());
    // If not empty
    ASSERT_EQ(collection -> size(), 5);
    // Resize
    collection -> resize(0);
    // Is collection empty
    ASSERT_TRUE(collection -> empty());
    // If empty
    ASSERT_EQ(collection -> size(), 0);
}

// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, ClearErasesCollection)
{
    add_entries(5);

    // Is collection empty
    ASSERT_FALSE(collection -> empty());
    // If not empty
    ASSERT_EQ(collection -> size(), 5);
    // Clear
    collection -> clear();
    // Is collection empty
    ASSERT_TRUE(collection -> empty());
    // If empty
    ASSERT_EQ(collection -> size(), 0);
}

// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, EraseClearsCollection)
{
    add_entries(5);

    // Is collection empty
    ASSERT_FALSE(collection -> empty());
    // If not empty
    ASSERT_EQ(collection -> size(), 5);
    // Clear
    collection -> erase(collection -> begin(), collection -> end());
    // Is collection empty
    ASSERT_TRUE(collection -> empty());
    // If empty
    ASSERT_EQ(collection -> size(), 0);
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, ReserveIncreaseCapacity)
{
    add_entries(1);

    // Is collection empty
    ASSERT_FALSE(collection -> empty());
    // If not empty
    ASSERT_EQ(collection -> size(), 1);
    // Check capacity
    ASSERT_EQ(collection -> capacity(), 1);

    collection ->reserve(5);

    // Check Capacity
    ASSERT_EQ(collection -> capacity(), 5);
    // Confirm size is 1
    ASSERT_EQ(collection -> size(), 1);
}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
TEST_F(CollectionTest, ThrowOutOfRange)
{
    add_entries(3);

    // Is collection empty
    ASSERT_FALSE(collection -> empty());
    // Check size
    ASSERT_EQ(collection -> size(), 3);
    //Check collection throw
    ASSERT_THROW(collection -> at(5), std::out_of_range);

}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative

// Test to verify insertion into collection
TEST_F(CollectionTest, InsertCollection)
{
    add_entries(5);

    // Is collection empty
    ASSERT_FALSE(collection -> empty());
    // Verify collection size
    ASSERT_EQ(collection -> size(), 5);
    // Insert into collection
    collection -> emplace(collection -> begin(), 1);
    // Verify collection
    ASSERT_FALSE(collection -> empty());
    // Verify collection size
    ASSERT_EQ(collection -> size(), 6);

}

// Test to verify out of range when insertion beyond max size
TEST_F(CollectionTest, ReserveMoreThanAvaliable)
{

    add_entries(5);
    // Is collection empty
    ASSERT_FALSE(collection -> empty());
    // Check size
    ASSERT_EQ(collection -> size(), 5);
    // Insertion throw
    ASSERT_THROW(collection -> reserve(9999999999999999), std::bad_alloc);

}