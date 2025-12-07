#include "pch.h"
#include "CppUnitTest.h"
#include "session_duration.h"
#include "student_session.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    TEST_CLASS(SessionDurationTests)
    {
    public:

        // Тест 1: Пустой список сессий
        TEST_METHOD(TestEmptySessions)
        {
            vector<StudentSession> sessions;
            int result = calculateSessionDuration(sessions);
            Assert::AreEqual(0, result);
        }

        // Тест 2: Одна сессия 
        TEST_METHOD(TestSingleSession)
        {
            vector<StudentSession> sessions;
            StudentSession s;
            s.examDate = { 15, 1, 2025 };
            sessions.push_back(s);

            int result = calculateSessionDuration(sessions);
            Assert::AreEqual(0, result);
        }

        // Тест 3: Несколько сессий в одном месяце
        TEST_METHOD(TestMultipleSessionsSameMonth)
        {
            vector<StudentSession> sessions;

            StudentSession s1;
            s1.examDate = { 15, 1, 2025 };
            sessions.push_back(s1);

            StudentSession s2;
            s2.examDate = { 20, 1, 2025 };
            sessions.push_back(s2);

            StudentSession s3;
            s3.examDate = { 18, 1, 2025 };
            sessions.push_back(s3);

            int result = calculateSessionDuration(sessions);
            Assert::AreEqual(5, result); // 20 - 15 = 5 дней
        }

        // Тест 4: Сессии в разных месяцах
        TEST_METHOD(TestSessionsDifferentMonths)
        {
            vector<StudentSession> sessions;

            StudentSession s1;
            s1.examDate = { 25, 1, 2025 };
            sessions.push_back(s1);

            StudentSession s2;
            s2.examDate = { 5, 2, 2025 };
            sessions.push_back(s2);

            StudentSession s3;
            s3.examDate = { 15, 1, 2025 };
            sessions.push_back(s3);

            int result = calculateSessionDuration(sessions);
            Assert::AreEqual(11, result); // 11 дней между 25.01 и 05.02
        }
    };
}