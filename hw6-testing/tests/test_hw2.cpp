#include <gtest/gtest.h>
#include "text_editor.h"

TEST(TextEditorTest, AddText) {
    TextEditor ed;
    ed.addText("hello");
    EXPECT_EQ(ed.cursorLeft(5), "");
}

TEST(TextEditorTest, DeleteText) {
    TextEditor ed;
    ed.addText("hello");
    EXPECT_EQ(ed.deleteText(2), 2);
}

TEST(TextEditorTest, CursorLeft) {
    TextEditor ed;
    ed.addText("hello");
    EXPECT_EQ(ed.cursorLeft(2), "hel");
}

TEST(TextEditorTest, CursorRight) {
    TextEditor ed;
    ed.addText("hello");
    ed.cursorLeft(5);
    EXPECT_EQ(ed.cursorRight(3), "hel");
}

TEST(TextEditorTest, EmptyDelete) {
    TextEditor ed;
    EXPECT_EQ(ed.deleteText(5), 0);
}
