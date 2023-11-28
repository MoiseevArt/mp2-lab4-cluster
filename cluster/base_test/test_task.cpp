#include "Task.h"
#include <gtest.h>

TEST(Task, can_create_task)
{
    ASSERT_NO_THROW(task t(10, 5));
}

TEST(Task, runTact_returns_false_when_tacts_limit_reached)
{
    task t(2, 3);
    t.runTa�t();
    t.runTa�t();
    EXPECT_FALSE(t.runTa�t());
}

TEST(Task, runTact_returns_true_when_tacts_limit_not_reached)
{
    task t(2, 3);
    EXPECT_TRUE(t.runTa�t());
}

TEST(Task, can_getNodes)
{
    task t(2, 3);
    EXPECT_EQ(t.getNodes(), t.getNodes());
}

TEST(Task, can_getTacts)
{
    task t(2, 3);
    EXPECT_EQ(t.getTa�ts(), t.getTa�ts());
}

TEST(Task, can_getId)
{
    task t(2, 3);
    EXPECT_GE(t.getId(), 0);
}

TEST(Task, multiple_tasks_have_different_ids)
{
    task t1(2, 3);
    task t2(2, 3);
    EXPECT_NE(t1.getId(), t2.getId());
}

TEST(Task, multiple_tasks_have_consecutive_ids)
{
    task t1(2, 3);
    task t2(2, 3);
    EXPECT_EQ(t1.getId() + 1, t2.getId());
}