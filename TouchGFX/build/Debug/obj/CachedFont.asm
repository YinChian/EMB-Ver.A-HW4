; Listing generated by Microsoft (R) Optimizing Compiler Version 19.34.31933.0 

	TITLE	Z:\Embbed_System\Ray\MyApplication\TouchGFX\build\Debug\obj\CachedFont.obj
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
__CB807E67_Texts@hpp DB 01H
__40300FAF_TypedText@hpp DB 01H
__DF6692C5_FontManager@hpp DB 01H
__76858464_ApplicationFontProvider@hpp DB 01H
__E7C3C5ED_FontCache@hpp DB 01H
__5FF033BC_ConstFont@hpp DB 01H
__2921E288_GeneratedFont@hpp DB 01H
__0294AFE7_CachedFont@hpp DB 01H
__F4188F00_CachedFont@cpp DB 01H
msvcjmc	ENDS
PUBLIC	?getPixelData@FontCache@touchgfx@@SAPBEPBUGlyphNode@2@@Z ; touchgfx::FontCache::getPixelData
PUBLIC	?isCached@FontCache@touchgfx@@SA_NPBUGlyphNode@2@@Z ; touchgfx::FontCache::isCached
PUBLIC	?getGlyph@CachedFont@touchgfx@@UBEPBUGlyphNode@2@GAAPBEAAE@Z ; touchgfx::CachedFont::getGlyph
PUBLIC	?getPixelData@CachedFont@touchgfx@@UBEPBEPBUGlyphNode@2@@Z ; touchgfx::CachedFont::getPixelData
PUBLIC	?getKerning@CachedFont@touchgfx@@UBECGPBUGlyphNode@2@@Z ; touchgfx::CachedFont::getKerning
PUBLIC	__JustMyCode_Default
EXTRN	?getGlyph@FontCache@touchgfx@@QBEPBUGlyphNode@2@GG@Z:PROC ; touchgfx::FontCache::getGlyph
EXTRN	?find@ConstFont@touchgfx@@QBEPBUGlyphNode@2@G@Z:PROC ; touchgfx::ConstFont::find
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
;	COMDAT ?getKerning@CachedFont@touchgfx@@UBECGPBUGlyphNode@2@@Z
_TEXT	SEGMENT
_this$ = -8						; size = 4
_prevChar$ = 8						; size = 2
_glyph$ = 12						; size = 4
?getKerning@CachedFont@touchgfx@@UBECGPBUGlyphNode@2@@Z PROC ; touchgfx::CachedFont::getKerning, COMDAT
; _this$ = ecx
; File Z:\Embbed_System\Ray\MyApplication\TouchGFX\generated\fonts\src\CachedFont.cpp
; Line 51
	push	ebp
	mov	ebp, esp
	sub	esp, 204				; 000000ccH
	push	ebx
	push	esi
	push	edi
	push	ecx
	lea	edi, DWORD PTR [ebp-12]
	mov	ecx, 3
	mov	eax, -858993460				; ccccccccH
	rep stosd
	pop	ecx
	mov	DWORD PTR _this$[ebp], ecx
	mov	ecx, OFFSET __F4188F00_CachedFont@cpp
	call	@__CheckForDebuggerJustMyCode@4
; Line 53
	xor	al, al
; Line 54
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 204				; 000000ccH
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	8
?getKerning@CachedFont@touchgfx@@UBECGPBUGlyphNode@2@@Z ENDP ; touchgfx::CachedFont::getKerning
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
;	COMDAT ?getPixelData@CachedFont@touchgfx@@UBEPBEPBUGlyphNode@2@@Z
_TEXT	SEGMENT
_data$1 = -20						; size = 4
_this$ = -8						; size = 4
_glyph$ = 8						; size = 4
?getPixelData@CachedFont@touchgfx@@UBEPBEPBUGlyphNode@2@@Z PROC ; touchgfx::CachedFont::getPixelData, COMDAT
; _this$ = ecx
; File Z:\Embbed_System\Ray\MyApplication\TouchGFX\generated\fonts\src\CachedFont.cpp
; Line 9
	push	ebp
	mov	ebp, esp
	sub	esp, 216				; 000000d8H
	push	ebx
	push	esi
	push	edi
	push	ecx
	lea	edi, DWORD PTR [ebp-24]
	mov	ecx, 6
	mov	eax, -858993460				; ccccccccH
	rep stosd
	pop	ecx
	mov	DWORD PTR _this$[ebp], ecx
	mov	ecx, OFFSET __F4188F00_CachedFont@cpp
	call	@__CheckForDebuggerJustMyCode@4
; Line 11
	mov	eax, DWORD PTR _glyph$[ebp]
	push	eax
	call	?isCached@FontCache@touchgfx@@SA_NPBUGlyphNode@2@@Z ; touchgfx::FontCache::isCached
	add	esp, 4
	movzx	ecx, al
	test	ecx, ecx
	je	SHORT $LN2@getPixelDa
; Line 13
	mov	eax, DWORD PTR _glyph$[ebp]
	push	eax
	call	?getPixelData@FontCache@touchgfx@@SAPBEPBUGlyphNode@2@@Z ; touchgfx::FontCache::getPixelData
	add	esp, 4
	mov	DWORD PTR _data$1[ebp], eax
; Line 14
	mov	eax, DWORD PTR _data$1[ebp]
	jmp	SHORT $LN1@getPixelDa
$LN2@getPixelDa:
; Line 16
	mov	esi, esp
	mov	eax, DWORD PTR _glyph$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	eax, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx]
	mov	ecx, DWORD PTR [eax+48]
	mov	eax, DWORD PTR [edx+72]
	call	eax
	cmp	esi, esp
	call	__RTC_CheckEsp
$LN1@getPixelDa:
; Line 17
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 216				; 000000d8H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	4
?getPixelData@CachedFont@touchgfx@@UBEPBEPBUGlyphNode@2@@Z ENDP ; touchgfx::CachedFont::getPixelData
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
;	COMDAT ?getGlyph@CachedFont@touchgfx@@UBEPBUGlyphNode@2@GAAPBEAAE@Z
_TEXT	SEGMENT
_fallbackChar$1 = -32					; size = 2
_n$ = -20						; size = 4
_this$ = -8						; size = 4
_unicode$ = 8						; size = 2
_pixelData$ = 12					; size = 4
_bitsPerPixel$ = 16					; size = 4
?getGlyph@CachedFont@touchgfx@@UBEPBUGlyphNode@2@GAAPBEAAE@Z PROC ; touchgfx::CachedFont::getGlyph, COMDAT
; _this$ = ecx
; File Z:\Embbed_System\Ray\MyApplication\TouchGFX\generated\fonts\src\CachedFont.cpp
; Line 20
	push	ebp
	mov	ebp, esp
	sub	esp, 228				; 000000e4H
	push	ebx
	push	esi
	push	edi
	push	ecx
	lea	edi, DWORD PTR [ebp-36]
	mov	ecx, 9
	mov	eax, -858993460				; ccccccccH
	rep stosd
	pop	ecx
	mov	DWORD PTR _this$[ebp], ecx
	mov	ecx, OFFSET __F4188F00_CachedFont@cpp
	call	@__CheckForDebuggerJustMyCode@4
; Line 22
	movzx	eax, WORD PTR _unicode$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+48]
	call	?find@ConstFont@touchgfx@@QBEPBUGlyphNode@2@G@Z ; touchgfx::ConstFont::find
	mov	DWORD PTR _n$[ebp], eax
; Line 24
	cmp	DWORD PTR _n$[ebp], 0
	jne	SHORT $LN2@getGlyph
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+44], 0
	je	SHORT $LN2@getGlyph
; Line 27
	mov	eax, DWORD PTR _this$[ebp]
	movzx	ecx, WORD PTR [eax+40]
	push	ecx
	movzx	edx, WORD PTR _unicode$[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	call	?getGlyph@FontCache@touchgfx@@QBEPBUGlyphNode@2@GG@Z ; touchgfx::FontCache::getGlyph
	mov	DWORD PTR _n$[ebp], eax
$LN2@getGlyph:
; Line 31
	cmp	DWORD PTR _n$[ebp], 0
	jne	SHORT $LN3@getGlyph
	movzx	eax, WORD PTR _unicode$[ebp]
	test	eax, eax
	je	SHORT $LN3@getGlyph
	movzx	eax, WORD PTR _unicode$[ebp]
	cmp	eax, 10					; 0000000aH
	je	SHORT $LN3@getGlyph
; Line 33
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx]
	mov	esi, esp
	mov	ecx, DWORD PTR [edx+48]
	mov	edx, DWORD PTR [eax+12]
	call	edx
	cmp	esi, esp
	call	__RTC_CheckEsp
	mov	WORD PTR _fallbackChar$1[ebp], ax
; Line 34
	movzx	eax, WORD PTR _fallbackChar$1[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+48]
	call	?find@ConstFont@touchgfx@@QBEPBUGlyphNode@2@G@Z ; touchgfx::ConstFont::find
	mov	DWORD PTR _n$[ebp], eax
; Line 35
	cmp	DWORD PTR _n$[ebp], 0
	jne	SHORT $LN3@getGlyph
; Line 37
	mov	eax, DWORD PTR _this$[ebp]
	movzx	ecx, WORD PTR [eax+40]
	push	ecx
	movzx	edx, WORD PTR _fallbackChar$1[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	call	?getGlyph@FontCache@touchgfx@@QBEPBUGlyphNode@2@GG@Z ; touchgfx::FontCache::getGlyph
	mov	DWORD PTR _n$[ebp], eax
$LN3@getGlyph:
; Line 41
	cmp	DWORD PTR _n$[ebp], 0
	je	SHORT $LN5@getGlyph
; Line 43
	mov	esi, esp
	mov	eax, DWORD PTR _n$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+72]
	call	eax
	cmp	esi, esp
	call	__RTC_CheckEsp
	mov	ecx, DWORD PTR _pixelData$[ebp]
	mov	DWORD PTR [ecx], eax
; Line 44
	mov	eax, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [eax]
	mov	esi, esp
	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+48]
	call	eax
	cmp	esi, esp
	call	__RTC_CheckEsp
	mov	ecx, DWORD PTR _bitsPerPixel$[ebp]
	mov	BYTE PTR [ecx], al
; Line 45
	mov	eax, DWORD PTR _n$[ebp]
	jmp	SHORT $LN1@getGlyph
$LN5@getGlyph:
; Line 47
	xor	eax, eax
$LN1@getGlyph:
; Line 48
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 228				; 000000e4H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	12					; 0000000cH
?getGlyph@CachedFont@touchgfx@@UBEPBUGlyphNode@2@GAAPBEAAE@Z ENDP ; touchgfx::CachedFont::getGlyph
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
;	COMDAT ?isCached@FontCache@touchgfx@@SA_NPBUGlyphNode@2@@Z
_TEXT	SEGMENT
tv66 = -196						; size = 4
_g$ = 8							; size = 4
?isCached@FontCache@touchgfx@@SA_NPBUGlyphNode@2@@Z PROC ; touchgfx::FontCache::isCached, COMDAT
; File Z:\Embbed_System\Ray\MyApplication\TouchGFX\generated\fonts\include\fonts\FontCache.hpp
; Line 52
	push	ebp
	mov	ebp, esp
	sub	esp, 196				; 000000c4H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-4]
	mov	ecx, 1
	mov	eax, -858993460				; ccccccccH
	rep stosd
	mov	ecx, OFFSET __E7C3C5ED_FontCache@hpp
	call	@__CheckForDebuggerJustMyCode@4
; Line 53
	mov	eax, DWORD PTR _g$[ebp]
	cmp	DWORD PTR [eax], -1
	jne	SHORT $LN3@isCached
	mov	DWORD PTR tv66[ebp], 1
	jmp	SHORT $LN4@isCached
$LN3@isCached:
	mov	DWORD PTR tv66[ebp], 0
$LN4@isCached:
	mov	al, BYTE PTR tv66[ebp]
; Line 54
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 196				; 000000c4H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?isCached@FontCache@touchgfx@@SA_NPBUGlyphNode@2@@Z ENDP ; touchgfx::FontCache::isCached
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
;	COMDAT ?getPixelData@FontCache@touchgfx@@SAPBEPBUGlyphNode@2@@Z
_TEXT	SEGMENT
_glyph$ = 8						; size = 4
?getPixelData@FontCache@touchgfx@@SAPBEPBUGlyphNode@2@@Z PROC ; touchgfx::FontCache::getPixelData, COMDAT
; File Z:\Embbed_System\Ray\MyApplication\TouchGFX\generated\fonts\include\fonts\FontCache.hpp
; Line 48
	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	mov	edi, ebp
	xor	ecx, ecx
	mov	eax, -858993460				; ccccccccH
	rep stosd
	mov	ecx, OFFSET __E7C3C5ED_FontCache@hpp
	call	@__CheckForDebuggerJustMyCode@4
; Line 49
	mov	eax, DWORD PTR _glyph$[ebp]
	add	eax, 20					; 00000014H
; Line 50
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 192				; 000000c0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?getPixelData@FontCache@touchgfx@@SAPBEPBUGlyphNode@2@@Z ENDP ; touchgfx::FontCache::getPixelData
_TEXT	ENDS
END
