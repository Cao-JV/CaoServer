/**
 * @file ATerminalService.hpp
 * @author Cao S (cao@jaggedverge.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-14
 * 
 * @copyright Copyright (c) 2022
 * 
 * Create wrappers, so that we can incorporate libraries/padded functionality & switch out in a central location
 */
#ifndef ATERMINALSERVICE_HPP
#define ATERMINALSERVICE_HPP
#include "AStdTerminal.hpp"
             template <typename CharType, typename StringType>
             class ATerminalService : AStdTerminal<CharType, StringType> {
                 public:
                    AStdTerminal() = default;
                    virtual ~AStdTerminal() = default;
                    virtual void ClearScreen() = 0;
                    virtual void ClearLine()   = 0;
                    virtual void FlushOut()    = 0;
                    virtual void Print(const CharType Char) = 0;
                    virtual void Print(const StringType Format, ...) = 0;
                    virtual void Print(const CharType *Format, ...) = 0;
                    void VPrint(const StringType Format, va_list Args);
                    virtual void PrintLn(const CharType *Format, ...) =0;
                    virtual void PrintLn(const StringType Format, ...) = 0;
                    virtual int  GetChar(const int TimeOutMS = 0) = 0;
                    virtual StringType GetLine(const CharType Terminator, const int MaxLength = 0, const int TimeOutMS = 0) = 0;
                    virtual void GetMaxXY(int &X, int &Y) = 0;
                    virtual void GetXY(int &X, int &Y) = 0;
                    virtual void SetMaxXY(const int X, const int Y) = 0;
                    virtual void SetXY(const int X, const int Y, const bool AsEdit = true) = 0;
                    virtual void CursorMove(const int Value, const TerminalCursorMovement Movement) = 0;
                    virtual void SaveXY() = 0;
                    virtual void RestoreXY() = 0;
                    virtual void SetForegroundColour(const int ForegroundColour) = 0;
                    virtual void SetBackgroundColour(const int BackgroundColour) = 0;
                    virtual void SetTerminalAttribute(const TerminalAttributes Attribute, bool State) = 0;
                    virtual void SetConsoleColourMode(const TerminalColourModes Mode) = 0;
                    virtual TerminalColourModes GetConsoleColourMode() = 0;
                    virtual bool IsTerminalAttributeOn(const TerminalAttributes Attribute) = 0;
                protected:
                    const StringType EscapeSequenceBegin;
                    int                  m_SavedX
                                        ,m_SavedY
                                        ,m_CurrentX
                                        ,m_CurrentY
                                        ,m_MaxX
                                        ,m_MaxY
                                        ,m_ForegroundColour   = 7
                                        ,m_BackgroundColour   = 0;
                    TerminalColourModes  m_ColourMode        = TerminalColourModes::Modern;
                    TerminalAttributes   m_TerminalAttributes = TerminalAttributes::Echo | TerminalAttributes::ExtendedAscii;
                    virtual void         _initialize(bool EchoOn) = 0;
                    virtual void         _updateTerminalSettings(TerminalAttributes Attribute, bool State, bool WriteSettingsNow = true) = 0;
                    virtual void         _loadTerminalSettings() = 0;
                    virtual StringType   _translate(const CharType Char) = 0;
                    virtual StringType   _translate(const StringType) = 0;
            };
        }
#endif // ATERMINALSERVICE_HPP