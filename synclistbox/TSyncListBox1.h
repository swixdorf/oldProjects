//---------------------------------------------------------------------------

#ifndef TSyncListBox1H
#define TSyncListBox1H
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
class TSyncListBox1 : public TCustomListBox
{
private:
  virtual void __fastcall HandleVScroll( 
                          TMessage& msg );
  TCustomListBox *pSyncBox;

protected:
  BEGIN_MESSAGE_MAP
    MESSAGE_HANDLER(WM_VSCROLL, TMessage, 
                    HandleVScroll)
    END_MESSAGE_MAP(TCustomListBox)
public:
  __fastcall TSyncListBox(TComponent* Owner);
   void SetSyncListBox(
         TCustomListBox *pListBox )
   {
       pSyncBox = pListBox;
   }
__published:
};
//---------------------------------------------------------------------------
#endif
