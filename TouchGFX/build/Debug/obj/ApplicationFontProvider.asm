; Listing generated by Microsoft (R) Optimizing Compiler Version 19.34.31933.0 

	TITLE	Z:\Embbed_System\Ray\MyApplication\TouchGFX\build\Debug\obj\ApplicationFontProvider.obj
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRTD
INCLUDELIB OLDNAMES

msvcjmc	SEGMENT
__CD417A16_concurrencysal@h DB 01H
__18C11F8D_sal@h DB 01H
__BD42D05E_vadefs@h DB 01H
__2DC9DF70_vcruntime@h DB 01H
__F19000F7_stdarg@h DB 01H
__6569C2CA_corecrt@h DB 01H
__C3DF3361_assert@h DB 01H
__C54FBE38_stdint@h DB 01H
__0EB1E9B7_Config@hpp DB 01H
__9321F6EE_Types@hpp DB 01H
__D95AB97E_Unicode@hpp DB 01H
__61C7DD0A_Font@hpp DB 01H
__DF6692C5_FontManager@hpp DB 01H
__76858464_ApplicationFontProvider@hpp DB 01H
__5FF033BC_ConstFont@hpp DB 01H
__2921E288_GeneratedFont@hpp DB 01H
__CB807E67_Texts@hpp DB 01H
__40300FAF_TypedText@hpp DB 01H
__AECCA9B0_TypedTextDatabase@hpp DB 01H
__8B793957_ApplicationFontProvider@cpp DB 01H
msvcjmc	ENDS
PUBLIC	?getFont@ApplicationFontProvider@@UAEPAVFont@touchgfx@@G@Z ; ApplicationFontProvider::getFont
PUBLIC	__JustMyCode_Default
EXTRN	?getFonts@TypedTextDatabase@@YAPAPBVFont@touchgfx@@XZ:PROC ; TypedTextDatabase::getFonts
EXTRN	@__CheckForDebuggerJustMyCode@4:PROC
EXTRN	__RTC_CheckEsp:PROC
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
; Function compile flags: /Odt
;	COMDAT __JustMyCode_Default
_TEXT	SEGMENT
__JustMyCode_Default PROC				; COMDAT
	push	ebp
	mov	ebp, esp
	pop	ebp
	ret	0
__JustMyCode_Default ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
;	COMDAT ?getFont@ApplicationFontProvider@@UAEPAVFont@touchgfx@@G@Z
_TEXT	SEGMENT
tv65 = -208						; size = 4
_this$ = -8						; size = 4
_typography$ = 8					; size = 2
?getFont@ApplicationFontProvider@@UAEPAVFont@touchgfx@@G@Z PROC ; ApplicationFontProvider::getFont, COMDAT
; _this$ = ecx
; File Z:\Embbed_System\Ray\MyApplication\TouchGFX\generated\fonts\src\ApplicationFontProvider.cpp
; Line 9
	push	ebp
	mov	ebp, esp
	sub	esp, 208				; 000000d0H
	push	ebx
	push	esi
	push	edi
	push	ecx
	lea	edi, DWORD PTR [ebp-16]
	mov	ecx, 4
	mov	eax, -858993460				; ccccccccH
	rep stosd
	pop	ecx
	mov	DWORD PTR _this$[ebp], ecx
	mov	ecx, OFFSET __8B793957_ApplicationFontProvider@cpp
	call	@__CheckForDebuggerJustMyCode@4
; Line 10
	movzx	eax, WORD PTR _typography$[ebp]
	mov	DWORD PTR tv65[ebp], eax
	cmp	DWORD PTR tv65[ebp], 0
	je	SHORT $LN4@getFont
	cmp	DWORD PTR tv65[ebp], 1
	je	SHORT $LN5@getFont
	cmp	DWORD PTR tv65[ebp], 2
	je	SHORT $LN6@getFont
	jmp	SHORT $LN7@getFont
$LN4@getFont:
; Line 14
	call	?getFonts@TypedTextDatabase@@YAPAPBVFont@touchgfx@@XZ ; TypedTextDatabase::getFonts
	mov	ecx, 4
	imul	edx, ecx, 0
	mov	eax, DWORD PTR [eax+edx]
	jmp	SHORT $LN1@getFont
$LN5@getFont:
; Line 17
	call	?getFonts@TypedTextDatabase@@YAPAPBVFont@touchgfx@@XZ ; TypedTextDatabase::getFonts
	mov	ecx, 4
	shl	ecx, 0
	mov	eax, DWORD PTR [eax+ecx]
	jmp	SHORT $LN1@getFont
$LN6@getFont:
; Line 20
	call	?getFonts@TypedTextDatabase@@YAPAPBVFont@touchgfx@@XZ ; TypedTextDatabase::getFonts
	mov	ecx, 4
	shl	ecx, 1
	mov	eax, DWORD PTR [eax+ecx]
	jmp	SHORT $LN1@getFont
$LN7@getFont:
; Line 22
	xor	eax, eax
$LN1@getFont:
; Line 24
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 208				; 000000d0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	4
?getFont@ApplicationFontProvider@@UAEPAVFont@touchgfx@@G@Z ENDP ; ApplicationFontProvider::getFont
_TEXT	ENDS
END