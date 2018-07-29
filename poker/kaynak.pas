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
  shdocvw,Windows,Forms, Messages,OleCtrls, SysUtils, Variants, Classes, Graphics, Controls,MSHTML,ActiveX;

type
  TMyCallBack = procedure(Veri:string);cdecl;

function WB_SaveHTMLCode(WebBrowser: TWebBrowser; const FileName: TFileName): Boolean;
function WB_GetHTMLCode(WebBrowser: TWebBrowser; ACode: TStrings): Boolean;
function WB_GetCookieCode(WebBrowser: TWebBrowser): String;
function WB_SetValue(WebBrowser: TWebBrowser;fiedname:string;value:string): Boolean;
function WB_Post(WebBrowser: TWebBrowser): Boolean;
function WB_GetHTMLCode1(WebBrowser: TWebBrowser): String;
function SaveWBFrames(WebBrowser1: TWebBrowser):  string;
function GetFrame(WebBrowser1: TWebBrowser;FrameNo: Integer): IWebbrowser2;
function GetFrame_Sc(iw:IWebbrowser2;i: Integer):String;
 function WB_GetFrameCode(ps: IPersistStreamInit; ACode: TStrings): Boolean;
 function FrameYaz(Browser: TWebBrowser;Lines: TStrings): Boolean;
 procedure IterateFrames(const AWB: IWebBrowser2;TGonder: TMyCallBack);
 function WB_PostFormName(WebBrowser: TWebBrowser; FormName:String): Boolean;

    implementation

procedure IterateFrames(const AWB: IWebBrowser2;TGonder: TMyCallBack);
  var
    Doc: IHTMLDocument2;
    Container: IOleContainer;
    Enumerator: ActiveX.IEnumUnknown;
    Unknown: IUnknown;
    Browser: IWebBrowser2;
    Fetched: Longint;

  begin

    if (Assigned(AWB.Document))
       and (Supports(AWB.Document, IHTMLDocument2, Doc))
    then begin
      // Recursive searching.
      // ACHTUNG! We cannot use the document's frames collection here, because it
      // does not work in every case (i.e. Documents from a foreign domain).
      // Taken from http://support.microsoft.com/support/kb/articles/Q196/3/40.ASP
      if (Supports(Doc, IOleContainer, Container))
         and (Container.EnumObjects(OLECONTF_EMBEDDINGS, Enumerator) = S_OK)
      then begin
        while Enumerator.Next(1, Unknown, @Fetched) = S_OK do
          if (Supports(Unknown, IWebBrowser2, Browser))
          then begin
         //   TGonder(doc.body.outerhtml);
         if Assigned(TGonder) then
            begin
            TGonder(doc.body.outerhtml);
            end;
            IterateFrames(browser,TGonder);
          end;
      end;
    end;
  end;

function FrameYaz(Browser: TWebBrowser;Lines: TStrings): Boolean;
 var
  Document    : IHTMLDocument2;
  FrameDoc    : IHTMLDocument2;
  Frames      : IHTMLFramesCollection2;
  All         : IHtmlElementCollection;
  HtmlElement : IHtmlElement;
  idisp       : IDispatch;
  i,j         : Integer;
  v           : OleVariant;
  win2        : IHTMLWindow2;
  str_ready   :string;
begin
  // Lines.Clear;
  Browser.Document.QueryInterface(iHTMLDocument2,Document);
  Frames := Document.get_frames;
  All := Document.All;
  for i:=0 to All.length-1 do
  begin
    HTMLElement := All.Item(i,0) as IHTMLElement;
    if (Assigned(HTMLElement)) then
    begin
      if (HTMLElement.TagName='FRAME') then
      begin
        v := HTMLElement.getAttribute('Name',0);
        lines.add('============================ FRAME FOUND ==');
        lines.add(' ==>FRAME NAME: '+v);
        idisp := Frames.item(v);
        // now we get the window-object
        idisp.QueryInterface(IHTMLWindow2,win2);
        if (Assigned(win2)) then
        begin
          // here it comes, the IHTMLDocument2
          FrameDoc := win2.document;
          if (Assigned(FrameDoc)) then
          begin
           // we have to wait for the document until it is loaded ...
             // ...now it is safe to go on with work...
            for j:=0 to FrameDoc.all.length-1 do
            begin
              // showing the doc.elements for demo purposes
              HTMLElement := FrameDoc.All.Item(j,0) as IHTMLElement;
              lines.add('Element : ['+HTMLElement.TagName+']');
            end;
          end;
        end;
      end;
    end;
  end;
end;

function GetFrame_Sc(iw:IWebbrowser2;i: Integer):String;
var
  IpStream: IPersistStreamInit;
  AStream: TMemoryStream;

  sl: TStringList;
begin


    AStream := TMemoryStream.Create;
    try
      IpStream := iw.document as IPersistStreamInit;
      if Succeeded(IpStream.save(TStreamadapter.Create(AStream), True)) then
      begin
        AStream.Seek(0, 0);
        sl := TStringList.Create;
        sl.LoadFromStream(AStream);
        sl.SaveToFile('frame' + IntToStr(i) + '.txt');
        //  memo1.Lines.LoadFromStream(AStream);
         Result:=sl.Text;
        sl.Free;

      end;
    except
    end;
    AStream.Free;

end;

function GetFrame(WebBrowser1: TWebBrowser;FrameNo: Integer): IWebbrowser2;
var
  OleContainer: IOleContainer;
  enum: IEnumUnknown;
  unk: IUnknown;
  Fetched: PLongint;
begin

  if Assigned(Webbrowser1.document) then
  begin
    Fetched := nil;
    OleContainer := Webbrowser1.Document as IOleContainer;
    OleContainer.EnumObjects(OLECONTF_EMBEDDINGS, Enum);
    Enum.Skip(FrameNo);
    Enum.Next(1, Unk, Fetched);
    Result := Unk as IWebbrowser2;
  end
  else
    Result := nil;
end;

procedure WBLoadHTML(WebBrowser: TWebBrowser; HTMLCode: string) ;
var
   sl: TStringList;
   ms: TMemoryStream;
begin
   WebBrowser.Navigate('about:blank') ;
   while WebBrowser.ReadyState < READYSTATE_INTERACTIVE do
    Application.ProcessMessages;

   if Assigned(WebBrowser.Document) then
   begin
     sl := TStringList.Create;
     try
       ms := TMemoryStream.Create;
       try
         sl.Text := HTMLCode;
         sl.SaveToStream(ms) ;
         ms.Seek(0, 0) ;
         (WebBrowser.Document as IPersistStreamInit).Load(TStreamAdapter.Create(ms)) ;
       finally
         ms.Free;
       end;
     finally
       sl.Free;
     end;
   end;
end;

 function GetFormByNumber(document: IHTMLDocument2;
    formNumber: integer): IHTMLFormElement;
var
  forms: IHTMLElementCollection;
begin
  forms := document.Forms as IHTMLElementCollection;
  if formNumber < forms.Length then
    result := forms.Item(formNumber,'') as IHTMLFormElement
  else
    result := nil;
end;

 function GetFormByName(document: IHTMLDocument2;
    const formName: string): IHTMLFormElement;
var
  forms: IHTMLElementCollection;
begin
  forms := document.Forms as IHTMLElementCollection;
  result := forms.Item(formName,'') as IHTMLFormElement
end;
procedure SetFieldValue(theForm: IHTMLFormElement;
  const fieldName: string; const newValue: string;
  const instance: integer=0);
var
  field: IHTMLElement;
  inputField: IHTMLInputElement;
  selectField: IHTMLSelectElement;
  textField: IHTMLTextAreaElement;
begin
  field := theForm.Item(fieldName,instance) as IHTMLElement;
  if Assigned(field) then
  begin
    if field.tagName = 'INPUT' then
    begin
      inputField := field as IHTMLInputElement;
      if (inputField.type_ <> 'radio') and
         (inputField.type_ <> 'checkbox')
      then
        inputField.value := newValue
      else
        inputField.checked := (newValue = 'checked');
    end
    else if field.tagName = 'SELECT' then
    begin
      selectField := field as IHTMLSelectElement;
      selectField.value := newValue;
    end
    else if field.tagName = 'TEXTAREA' then
    begin
      textField := field as IHTMLTextAreaElement;
      textField.value := newValue;
    end;
  end;
end;
function WB_PostFormName(WebBrowser: TWebBrowser; FormName:String): Boolean;
 var
   document: IHTMLDocument2;
  theForm: IHTMLFormElement;
  index: integer;
begin
  document := WebBrowser.Document as IHTMLDocument2;
  theForm := GetFormByName(document,FormName); //GetFormByNumber(document,0);
  theForm.submit;
end;

 function WB_Post(WebBrowser: TWebBrowser): Boolean;
 var
   document: IHTMLDocument2;
  theForm: IHTMLFormElement;
  index: integer;
begin
  document := WebBrowser.Document as IHTMLDocument2;
  theForm := GetFormByNumber(document,0);
  theForm.submit;
end;
function WB_SetValue(WebBrowser: TWebBrowser;fiedname:string;value:string): Boolean;
var
  document: IHTMLDocument2;
  theForm: IHTMLFormElement;
  index: integer;
begin
  document := WebBrowser.Document as IHTMLDocument2;
  theForm := GetFormByNumber(WebBrowser.Document as IHTMLDocument2,0);
  SetFieldValue(theForm,fiedname,value);
end;

function WB_SaveFrameToFile(HTMLDocument: IHTMLDocument2;
  const FileName: TFileName): Boolean;
// Save IHTMLDocument2 to a file
var
  PersistFile: IPersistFile;
begin
  PersistFile := HTMLDocument as IPersistFile;
  PersistFile.Save(StringToOleStr(FileName), System.True);
end;

function GetBrowserForFrame(Doc: IHTMLDocument2; nFrame: Integer): IWebBrowser2;
  //Thanks to Rik Barker
  //returns an interface to the frame's browser
var
  pContainer: IOLEContainer;
  enumerator: ActiveX.IEnumUnknown;
  nFetched: PLongInt;
  unkFrame: IUnknown;
  hr: HRESULT;
begin
  Result := nil;
  nFetched := nil;
  // Cast the page as an OLE container
  pContainer := Doc as IOleContainer;
  // Get an enumerator for the frames on the page
  hr := pContainer.EnumObjects(OLECONTF_EMBEDDINGS or OLECONTF_OTHERS, enumerator);
  if hr <> S_OK then
  begin
    pContainer._Release;
    Exit;
  end;
  // Now skip to the frame we're interested in
  enumerator.Skip(nFrame);
  // and get the frame as IUnknown
  enumerator.Next(1,unkFrame, nFetched);
  // Now QI the frame for a WebBrowser Interface - I'm not  entirely
  // sure this is necessary, but COM never ceases to surprise me
  unkframe.QueryInterface(IID_IWebBrowser2, Result);
end;

function GetFrameSource(WebDoc: iHTMLDocument2): string;
  //returns frame HTML and scripts as a text string
var
  re: integer;
  HTMLel: iHTMLElement;
  HTMLcol: iHTMLElementCollection;
  HTMLlen: Integer;
  ScriptEL: IHTMLScriptElement;
begin
  Result := '';
  if Assigned(WebDoc) then
  begin
    HTMLcol := WebDoc.Get_all;
    HTMLlen := HTMLcol.Length;
    for re := 0 to HTMLlen - 1 do
    begin
      HTMLel := HTMLcol.Item(re, 0) as iHTMLElement;
      if HTMLEl.tagName = 'HTML' then
        Result := Result + HTMLEl.outerHTML;
    end;
  end;
end;


function SaveWBFrames(WebBrowser1: TWebBrowser):  string;
// return the source for all frames in the browser
var
  Webdoc, HTMLDoc: ihtmldocument2;
  framesCol: iHTMLFramesCollection2;
  FramesLen: integer;
  pickFrame: olevariant;
  p: integer;
begin
  try
    WebDoc := WebBrowser1.Document as IHTMLDocument2;
    Result := GetFrameSource(WebDoc);

    // ��� Hier kann Result in eine Datei gespeichert werden ����  oder  mit
    // WB_SaveFrameToFile(WebDoc,'c:\MainPage.html');

    //Handle multiple or single frames
    FramesCol := WebDoc.Get_frames;
    FramesLen := FramesCol.Get_length;
    if FramesLen > 0 then
      for p := 0 to FramesLen - 1 do
      begin
        pickframe := p;
        HTMLDoc   := WebBrowser1.Document as iHTMLDocument2;

        WebDoc := GetBrowserForFrame(HTMLDoc, pickframe).document as iHTMLDocument2;
        if WebDoc <> nil then
        begin
          Result := GetFrameSource(WebDoc);
         // WB_SaveFrameToFile(WebDoc, 'c:\Frame' + IntToStr(p) + '.html');
          // ShowMessage(HTMLDoc.Get_parentWindow.Get_name);
          // ShowMessage(HTMLDoc.Get_parentWindow.Parent.Get_document.nameProp);

        end;
      end;
  except
    Result := 'No Source Available';
  end;
end;


function WB_GetHTMLCode1(WebBrowser: TWebBrowser): String;
var
    iall : IHTMLElement;
begin
   if Assigned(WebBrowser.Document) then
   begin
     iall := (WebBrowser.Document AS IHTMLDocument2).body;

     while iall.parentElement <> nil do
     begin
       iall := iall.parentElement;
     end;
    Result := iall.outerHTML;
   end;
end;

function WB_GetCookieCode(WebBrowser: TWebBrowser) : String;
var
  document: IHTMLDocument2;
  cookies: String;
begin
  document := WebBrowser.Document as IHTMLDocument2;
  if Assigned(document) then
  begin
    cookies := document.cookie;
  end;
  Result := cookies
    end;
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

 function WB_GetFrameCode(ps: IPersistStreamInit; ACode: TStrings): Boolean;
 var

  ss: TStringStream;
  sa: IStream;
  s: string;
  kon: integer;
begin
//  ps := WebBrowser.Document as IPersistStreamInit;

  if Assigned(ps) then
  begin
  s := '';
  ss := TStringStream.Create(s);
  try
    sa := TStreamAdapter.Create(ss, soReference) as IStream;
    Result := Succeeded(ps.Save(sa, True));
    if Result then
     ACode.Text:=ss.Datastring;
   // ACode.Add(ss.Datastring);
  finally
//    ss.Free;
  end;
   end;
end;



function WB_GetHTMLCode(WebBrowser: TWebBrowser; ACode: TStrings): Boolean;
var
  ps: IPersistStreamInit;
  ss: TStringStream;
  sa: IStream;
  s: string;
  kon: integer;
begin
  ps := WebBrowser.Document as IPersistStreamInit;

  if Assigned(ps) then
  begin
  s := '';
  ss := TStringStream.Create(s);
  try
    sa := TStreamAdapter.Create(ss, soReference) as IStream;
    Result := Succeeded(ps.Save(sa, True));
    if Result then
     ACode.Text:=ss.Datastring;
   // ACode.Add(ss.Datastring);
  finally
    ss.Free;
  end;
  end;
end;

end.