unit UTF8;

{-----------------------------------------------------------------------------
 Unit Name: UTF8
 extracted from LibXmlParser
 Author:    Stefan Heymann (stefan@destructor.de)
 Purpose:   UTF8 conversion routines (those included in Kylix don't work)
 Version:   v. 1.0
 Licence:   "Destructor.de Source code Licence" (DSL)

The official site to get this parser is http://www.destructor.de/

Usage and Distribution of this Source Code is ruled by the
"Destructor.de Source code Licence" (DSL) which comes with this file or
can be downloaded at http://www.destructor.de/

IN SHORT: Usage and distribution of this source code is free.
					You use it completely on your own risk

-----------------------------------------------------------------------------}

interface

function Utf8ToAnsi(Source: string; UnknownChar: char = ' '): AnsiString;
function AnsiToUtf8(Source: AnsiString): string;

implementation

const
	// --- Character Translation Table for Unicode <-> Win-1252
	WIN1252_UNICODE : array [$00..$FF] of word = (
										$0000, $0001, $0002, $0003, $0004, $0005, $0006, $0007, $0008, $0009,
										$000A, $000B, $000C, $000D, $000E, $000F, $0010, $0011, $0012, $0013,
										$0014, $0015, $0016, $0017, $0018, $0019, $001A, $001B, $001C, $001D,
										$001E, $001F, $0020, $0021, $0022, $0023, $0024, $0025, $0026, $0027,
										$0028, $0029, $002A, $002B, $002C, $002D, $002E, $002F, $0030, $0031,
										$0032, $0033, $0034, $0035, $0036, $0037, $0038, $0039, $003A, $003B,
										$003C, $003D, $003E, $003F, $0040, $0041, $0042, $0043, $0044, $0045,
										$0046, $0047, $0048, $0049, $004A, $004B, $004C, $004D, $004E, $004F,
										$0050, $0051, $0052, $0053, $0054, $0055, $0056, $0057, $0058, $0059,
										$005A, $005B, $005C, $005D, $005E, $005F, $0060, $0061, $0062, $0063,
										$0064, $0065, $0066, $0067, $0068, $0069, $006A, $006B, $006C, $006D,
										$006E, $006F, $0070, $0071, $0072, $0073, $0074, $0075, $0076, $0077,
										$0078, $0079, $007A, $007B, $007C, $007D, $007E, $007F,

										$20AC, $0081, $201A, $0192, $201E, $2026, $2020, $2021, $02C6, $2030,
										$0160, $2039, $0152, $008D, $017D, $008F, $0090, $2018, $2019, $201C,
										$201D, $2022, $2013, $2014, $02DC, $2122, $0161, $203A, $0153, $009D,
										$017E, $0178, $00A0, $00A1, $00A2, $00A3, $00A4, $00A5, $00A6, $00A7,
										$00A8, $00A9, $00AA, $00AB, $00AC, $00AD, $00AE, $00AF, $00B0, $00B1,
										$00B2, $00B3, $00B4, $00B5, $00B6, $00B7, $00B8, $00B9, $00BA, $00BB,
										$00BC, $00BD, $00BE, $00BF, $00C0, $00C1, $00C2, $00C3, $00C4, $00C5,
										$00C6, $00C7, $00C8, $00C9, $00CA, $00CB, $00CC, $00CD, $00CE, $00CF,
										$00D0, $00D1, $00D2, $00D3, $00D4, $00D5, $00D6, $00D7, $00D8, $00D9,
										$00DA, $00DB, $00DC, $00DD, $00DE, $00DF, $00E0, $00E1, $00E2, $00E3,
										$00E4, $00E5, $00E6, $00E7, $00E8, $00E9, $00EA, $00EB, $00EC, $00ED,
										$00EE, $00EF, $00F0, $00F1, $00F2, $00F3, $00F4, $00F5, $00F6, $00F7,
										$00F8, $00F9, $00FA, $00FB, $00FC, $00FD, $00FE, $00FF);

(* UTF-8  (somewhat simplified)
	-----
	Character Range    Byte sequence
	---------------    --------------------------     (x=Bits from original character)
	$0000..$007F       0xxxxxxx
	$0080..$07FF       110xxxxx 10xxxxxx
	$8000..$FFFF       1110xxxx 10xxxxxx 10xxxxxx

	Example
	--------
	Transforming the Unicode character U+00E4 LATIN SMALL LETTER A WITH DIAERESIS  (""):

				ISO-8859-1,           Decimal  228
				Win1252,              Hex      $E4
				ANSI                  Bin      1110 0100
																				abcd efgh

				UTF-8                 Binary   1100xxab 10cdefgh
															Binary   11000011 10100100
															Hex      $C3      $A4
															Decimal  195      164
															ANSI                      *)

function AnsiToUtf8(Source: AnsiString): string;
     (* Converts the given Windows ANSI (Win1252) String to UTF-8. *)
var
  I: INTEGER; // Loop counter
  U: WORD; // Current Unicode value
  Len: INTEGER; // Current real length of "Result" string
begin
  SetLength(Result, Length(Source) * 3); // Worst case
  Len := 0;
  for I := 1 to Length(Source) do begin
    U := WIN1252_UNICODE[ORD(Source[I])];
    case U of
      $0000..$007F: begin
          INC(Len);
          Result[Len] := CHR(U);
        end;
      $0080..$07FF: begin
          INC(Len);
          Result[Len] := CHR($C0 or (U shr 6));
          INC(Len);
          Result[Len] := CHR($80 or (U and $3F));
        end;
      $0800..$FFFF: begin
          INC(Len);
          Result[Len] := CHR($E0 or (U shr 12));
          INC(Len);
          Result[Len] := CHR($80 or ((U shr 6) and $3F));
          INC(Len);
          Result[Len] := CHR($80 or (U and $3F));
        end;
    end;
  end;
  SetLength(Result, Len);
end;


function Utf8ToAnsi(Source: string; UnknownChar: char = ' '): AnsiString;
     (* Converts the given UTF-8 String to Windows ANSI (Win-1252).
      If a character can not be converted, the "UnknownChar" is inserted. *)
var
  SourceLen: INTEGER; // Length of Source string
  I, K: INTEGER;
  A: BYTE; // Current ANSI character value
  U: WORD;
  Ch: CHAR; // Dest char
  Len: INTEGER; // Current real length of "Result" string
begin
  SourceLen := Length(Source);
  SetLength(Result, SourceLen); // Enough room to live
  Len := 0;
  I := 1;
  while I <= SourceLen do begin
    A := ORD(Source[I]);
    if A < $80 then begin // Range $0000..$007F
      INC(Len);
      Result[Len] := Source[I];
      INC(I);
    end
    else begin // Determine U, Inc I
      if (A and $E0 = $C0) and (I < SourceLen) then begin // Range $0080..$07FF
        U := (WORD(A and $1F) shl 6) or (ORD(Source[I + 1]) and $3F);
        INC(I, 2);
      end
      else if (A and $F0 = $E0) and (I < SourceLen - 1) then begin // Range $0800..$FFFF
        U := (WORD(A and $0F) shl 12) or
          (WORD(ORD(Source[I + 1]) and $3F) shl 6) or
          (ORD(Source[I + 2]) and $3F);
        INC(I, 3);
      end
      else begin // Unknown/unsupported
        INC(I);
        for K := 7 downto 0 do
          if A and (1 shl K) = 0 then begin
            INC(I, (A shr (K + 1)) - 1);
            BREAK;
          end;
        U := WIN1252_UNICODE[ORD(UnknownChar)];
      end;
      Ch := UnknownChar; // Retrieve ANSI char
      for A := $00 to $FF do
        if WIN1252_UNICODE[A] = U then begin
          Ch := CHR(A);
          BREAK;
        end;
      INC(Len);
      Result[Len] := Ch;
    end;
  end;
  SetLength(Result, Len);
end;


end.
 