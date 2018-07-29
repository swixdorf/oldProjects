{
Unit kaynak;

interface
uses
  ActiveX,  Windows, Messages,OleCtrls,shdocvw, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs;

  implementation
function WB_SaveHTMLCode(WebBrowser: TWebBrowser; const FileName:
TFileName): Boolean;
var
  ps: IPersistStreamInit;
  fs: TFileStream;
  sa: IStream;
begin
  ps := WebBrowser.Document as IPersistStreamInit;
  fs := TFileStream.Create(FileName, fmCreate);
  try
    sa := TStreamAdapter.Create(fs, soReference) as IStream;
    Result := Succeeded(ps.Save(sa, True));
  finally
    fs.Free;
  end;
end;

function WB_GetHTMLCode(WebBrowser: TWebBrowser; ACode: TStrings): Boolean;
var
  ps: IPersistStreamInit;
  ss: TStringStream;
  sa: IStream;
  s: string;
begin
  ps := WebBrowser.Document as IPersistStreamInit;
  s := '';
  ss := TStringStream.Create(s);
  try
    sa := TStreamAdapter.Create(ss, soReference) as IStream;
    Result := Succeeded(ps.Save(sa, True));
    if Result then ACode.Add(ss.Datastring);
  finally
    ss.Free;
  end;
end;
end.
}
Unit kaynak;
interface
uses
  shdocvw,Windows, Messages,OleCtrls, SysUtils, Variants, Classes, Graphics, Controls,ActiveX;


function WB_SaveHTMLCode(WebBrowser: TWebBrowser; const FileName: TFileName): Boolean;
function WB_GetHTMLCode(WebBrowser: TWebBrowser; ACode: TStrings): Boolean;

    implementation
function WB_SaveHTMLCode(WebBrowser: TWebBrowser; const FileName:
TFileName): Boolean;
var
  ps: IPersistStreamInit;
  fs: TFileStream;
  sa: IStream;
begin
  ps := WebBrowser.Document as IPersistStreamInit;
  fs := TFileStream.Create(FileName, fmCreate);
  try
    sa := TStreamAdapter.Create(fs, soReference) as IStream;
    Result := Succeeded(ps.Save(sa, True));
  finally
    fs.Free;
  end;
end;

function WB_GetHTMLCode(WebBrowser: TWebBrowser; ACode: TStrings): Boolean;
var
  ps: IPersistStreamInit;
  ss: TStringStream;
  sa: IStream;
  s: string;
begin
  ps := WebBrowser.Document as IPersistStreamInit;
  s := '';
  ss := TStringStream.Create(s);
  try
    sa := TStreamAdapter.Create(ss, soReference) as IStream;
    Result := Succeeded(ps.Save(sa, True));             //hata verio downloadda;
    if Result then ACode.Add(ss.Datastring);
  finally
    ss.Free;
  end;
end;

end.
