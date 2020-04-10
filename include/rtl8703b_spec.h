System.Double)">
      <summary>Imposta il valore della proprietà <see cref="P:System.Windows.Controls.VirtualizingStackPanel.HorizontalOffset" />.</summary>
      <param name="offset">Valore della proprietà <see cref="P:System.Windows.Controls.VirtualizingStackPanel.HorizontalOffset" />.</param>
    </member>
    <member name="M:System.Windows.Controls.VirtualizingStackPanel.SetVerticalOffset(System.Double)">
      <summary>Imposta il valore della proprietà <see cref="P:System.Windows.Controls.VirtualizingStackPanel.VerticalOffset" />.</summary>
      <param name="offset">Valore della proprietà <see cref="P:System.Windows.Controls.VirtualizingStackPanel.VerticalOffset" />.</param>
    </member>
    <member name="M:System.Windows.Controls.VirtualizingStackPanel.ShouldItemsChangeAffectLayoutCore(System.Boolean,System.Windows.Controls.Primitives.ItemsChangedEventArgs)">
      <summary>Restituisce un valore che indica se un elemento modificato in <see cref="T:System.Windows.Controls.ItemsControl" /> influisce sul layout del pannello.</summary>
      <returns>true se l'elemento modificato in <see cref="T:System.Windows.Controls.ItemsControl" /> influisce sul layout del pannello; in caso contrario, false.</returns>
      <param name="areItemChangesLocal">true se l'elemento modificato è un figlio diretto di <see cref="T:System.Windows.Controls.VirtualizingPanel" />; false se l'elemento modificato è un discendente indiretto di <see cref="T:System.Windows.Controls.VirtualizingPanel" />.</param>
      <param name="args">Contiene i dati relativi all'elemento modificato.</param>
    </member>
    <member name="P:System.Windows.Controls.VirtualizingStackPanel.VerticalOffset">
      <summary>Ottiene un valore che contiene l'offset verticale del contenuto a scorrimento.</summary>
      <returns>
        <see cref="T:System.Double" /> che rappresenta l'offset verticale del contenuto a scorrimento. Il valore predefinito è 0.0.</returns>
    </member>
    <member name="P:System.Windows.Controls.VirtualizingStackPanel.ViewportHeight">
      <summary>Ottiene un valore che contiene la dimensione verticale del riquadro di visualizzazione del contenuto.</summary>
      <returns>
        <see cref="T:System.Double" /> che rappresenta la dimensione verticale del riquadro di visualizzazione del contenuto. Il valore predefinito è 0.0.</returns>
    </member>
    <member name="P:System.Windows.Controls.VirtualizingStackPanel.ViewportWidth">
      <summary>Ottiene un valore che contiene la dimensione orizzontale del riquadro di visualizzazione del contenuto.</summary>
      <returns>
        <see cref="T:System.Double" /> che rappresenta la dimensione verticale del riquadro di visualizzazione del contenuto. Il valore predefinito è 0.0.</returns>
    </member>
    <member name="F:System.Windows.Controls.VirtualizingStackPanel.VirtualizationModeProperty">
      <summary>Identifica la proprietà associata VirtualizingStackPanel.VirtualizationMode.</summary>
      <returns>Identificatore per la proprietà associata VirtualizingStackPanel.VirtualizationMode.</returns>
    </member>
    <member name="T:System.Windows.Controls.WebBrowser">
      <summary>Ospita documenti di HTML tra cui consente di spostarsi. Consente l'interoperabilità tra codice gestito WPF e script HTML.</summary>
    </member>
    <member name="M:System.Windows.Controls.WebBrowser.#ctor">
      <summary>Inizializza una nuova istanza della classe <see cref="T:System.Windows.Controls.WebBrowser" />.</summary>
    </member>
    <member name="P:System.Windows.Controls.WebBrowser.CanGoBack">
      <summary>Ottiene un valore che indica se è presente un documento su cui tornare.</summary>
      <returns>Valore <see cref="T:System.Boolean" /> che indica se è presente un documento su cui tornare.</returns>
    </member>
    <member name="P:System.Windows.Controls.WebBrowser.CanGoForward">
      <summary>Ottiene un valore che indica se è presente un documento successivo su cui spostarsi.</summary>
      <returns>Valore <see cref="T:System.Boolean" /> che indica se è presente un documento successivo su cui spostarsi.</returns>
    </member>
    <member name="P:System.Windows.Controls.WebBrowser.Document">
      <summary>Ottiene l'oggetto Document che rappresenta la pagina HTML ospitata.</summary>
      <returns>Oggetto Document.</returns>
      <exception cref="T:System.ObjectDisposedException">L'istanza di <see cref="T:System.Windows.Controls.WebBrowser" /> non è più valida.</exception>
      <exception cref="T:System.InvalidOperationException">Impossibile recuperare un riferimento all'oggetto WebBrowser nativo sottostante.</exception>
    </member>
    <member name="M:System.Windows.Controls.WebBrowser.GoBack">
      <summary>Consente di tornare sul documento precedente, se presente.</summary>
      <exception cref="T:System.ObjectDisposedException">L'istanza di <see cref="T:System.Windows.Controls.WebBrowser" /> non è più valida.</exception>
      <exception cref="T:System.InvalidOperationException">Impossibile recuperare un riferimento all'oggetto WebBrowser nativo sottostante.</exception>
      <exception cref="T:System.Runtime.InteropServices.COMException">Non è presente alcun documento su cui tornare.</exception>
    </member>
    <member name="M:System.Windows.Controls.WebBrowser.GoForward">
      <summary>Consente di spostarsi avanti sul documento HTML successivo, se presente.</summary>
      <exception cref="T:System.ObjectDisposedException">L'istanza di <see cref="T:System.Windows.Controls.WebBrowser" /> non è più valida.</exception>
      <exception cref="T:System.InvalidOperationException">Impossibile recuperare un riferimento all'oggetto WebBrowser nativo sottostante.</exception>
      <exception cref="T:System.Runtime.InteropServices.COMException">Non è presente alcun documento successivo su cui spostarsi.</exception>
    </member>
    <member name="M:System.Windows.Controls.WebBrowser.InvokeScript(System.String)">
      <summary>Esegue una funzione di scripting implementata dal documento attualmente caricato.</summary>
      <returns>Oggetto restituito dalla chiamata di scripting.</returns>
      <param name="scriptName">Nome della funzione di scripting da eseguire.</param>
      <exception cref="T:System.ObjectDisposedException">L'istanza di <see cref="T:System.Windows.Controls.WebBrowser" /> non è più valida.</exception>
      <exception cref="T:System.InvalidOperationException">Impossibile recuperare un riferimento all'oggetto WebBrowser nativo sottostante.</exception>
      <exception cref="T:System.Runtime.InteropServices.COMException">La funzione di scripting non esiste.</exception>
    </member>
    <member name="M:System.Windows.Controls.WebBrowser.InvokeScript(System.String,System.Object[])">
      <summary>Esegue una funzione di scripting definita nel documento attualmente caricato.</summary>
      <returns>Oggetto restituito dalla chiamata di scripting.</returns>
      <param name="scriptName">Nome della funzione di scripting da eseguire.</param>
      <param name="args">Parametri da passare alla funzione di scripting.</param>
      <exception cref="T:System.ObjectDisposedException">L'istanza di <see cref="T:System.Windows.Controls.WebBrowser" /> non è più valida.</exception>
      <exception cref="T:System.InvalidOperationException">Impossibile recuperare un riferimento all'oggetto WebBrowser nativo sottostante.</exception>
      <exception cref="T:System.Runtime.InteropServices.COMException">La funzione di scripting non esiste.</exception>
    </member>
    <member name="E:System.Windows.Controls.WebBrowser.LoadCompleted">
      <summary>Si verifica quando termina il download del documento su cui si è effettuato lo spostamento.</summary>
    </member>
    <member name="M:System.Windows.Controls.WebBrowser.Navigate(System.String)">
      <summary>Passa in modo asincrono al documento corrispondente all'URL specificato.</summary>
      <param name="source">URL su cui spostarsi.</param>
    </member>
    <member name="M:System.Windows.Controls.WebBrowser.Navigate(System.String,System.String,System.Byte[],System.String)">
      <summary>Passa in modo asincrono al documento corrispondente all'URL specificato e specifica il frame di destinazione in cui caricare il contenuto del documento. È possibile inviare intestazioni HTTP e dati HTTP POST aggiuntivi al server come parte della richiesta di navigazione.</summary>
      <param name="source">URL su cui spostarsi.</param>
      <param name="targetFrameName">Nome del frame in cui visualizzare il contenuto del documento.</param>
      <param name="postData">Dati HTTP POST da inviare al server quando viene richiesta l'origine.</param>
      <param name="additionalHeaders">Intestazioni HTTP da inviare al server quando viene richiesta l'origine.</param>
    </member>
    <member name="M:System.Windows.Controls.WebBrowser.Navigate(System.Uri)">
      <summary>Consente di passare in modo asincrono al documento corrispondente all'oggetto <see cref="T:System.Uri" /> specificato.</summary>
      <param name="source">
        <see cref="T:System.Uri" /> su cui spostarsi.</param>
      <exception cref="T:System.ObjectDisposedException">L'istanza di <see cref="T:System.Windows.Controls.WebBrowser" /> non è più valida.</exception>
      <exception cref="T:System.InvalidOperationException">Impossibile recuperare un riferimento all'oggetto WebBrowser nativo sottostante.</exception>
      <exception cref="T:System.Security.SecurityException">Navigazione da un'applicazione eseguita in attendibilità parziale a un oggetto <see cref="T:System.Uri" /> che non si trova nel sito di origine.</exception>
    </member>
    <member name="M:System.Windows.Controls.WebBrowser.Navigate(System.Uri,System.String,System.Byte[],System.String)">
      <summary>Consente di passare in modo asincrono al documento corrispondente all'oggetto <see cref="T:System.Uri" /> specificato e di specificare il frame di destinazione in cui caricare il contenuto del documento. È possibile inviare intestazioni HTTP e dati HTTP POST aggiuntivi al server come parte della richiesta di navigazione.</summary>
      <param name="source">
        <see cref="T:System.Uri" /> su cui spostarsi.</param>
      <param name="targetFrameName">Nome del frame in cui visualizzare il contenuto del documento.</param>
      <param name="postData">Dati HTTP POST da inviare al server quando viene richiesta l'origine.</param>
      <param name="additionalHeaders">Intestazioni HTTP da inviare al server quando viene richiesta l'origine.</param>
      <exception cref="T:System.ObjectDisposedException">L'istanza di <see cref="T:System.Windows.Controls.WebBrowser" /> non è più valida.</exception>
      <exception cref="T:System.InvalidOperationException">Impossibile recuperare un riferimento all'oggetto WebBrowser nativo sottostante.</exception>
      <exception cref="T:System.Security.SecurityException">Navigazione da un'applicazione eseguita in attendibilità parziale: A un oggetto <see cref="T:System.Uri" /> che non si trova nel sito di origine oppure  Il nome <paramref name="targetFrameName" /> non è null o vuoto.</exception>
    </member>
    <member name="E:System.Windows.Controls.WebBrowser.Navigated">
      <summary>Si verifica quando il documento su cui viene effettuato lo spostamento viene individuato e ha avviato il download.</summary>
    </member>
    <member name="M:System.Windows.Controls.WebBrowser.NavigateToStream(System.IO.Stream)">
      <summary>Si sposta in modo asincrono a un oggetto <see cref="T:System.IO.Stream" /> che include il contenuto per un documento.</summary>
      <param name="stream">
        <see cref="T:System.IO.Stream" /> che contiene il contenuto per un documento.</param>
      <exception cref="T:System.ObjectDisposedException">L'istanza di <see cref="T:System.Windows.Controls.WebBrowser" /> non è più valida.</exception>
      <exception cref="T:System.InvalidOperationException">Impossibile recuperare un riferimento all'oggetto WebBrowser nativo sottostante.</exception>
    </member>
    <member name="M:System.Windows.Controls.WebBrowser.NavigateToString(System.String)">
      <summary>Si sposta in modo asincrono a un oggetto <see cref="T:System.String" /> che include il contenuto per un documento.</summary>
      <param name="text">
        <see cref="T:System.String" /> che contiene il contenuto per un documento.</param>
      <exception cref="T:System.ObjectDisposedException">L'istanza di <see cref="T:System.Windows.Controls.WebBrowser" /> non è più valida.</exception>
      <exception cref="T:System.InvalidOperationException">Impossibile recuperare un riferimento all'oggetto WebBrowser nativo sottostante.</exception>
    </member>
    <member name="E:System.Windows.Controls.WebBrowser.Navigating">
      <summary>Si verifica immediatamente prima della navigazione a un documento.</summary>
    </member>
    <member name="P:System.Windows.Controls.WebBrowser.ObjectForScripting">
      <summary>Ottiene o imposta un'istanza di una classe pubblica, implementata dall'applicazione host, a cui è possibile accedere tramite script da un documento ospitato.</summary>
      <returns>Oggetto <see cref="T:System.Object" /> che costituisce un'istanza di una classe public, implementata dall'applicazione host, a cui è possibile accedere tramite script da un documento ospitato.</returns>
      <exception cref="T:System.ArgumentException">
        <see cref="P:System.Windows.Controls.WebBrowser.ObjectForScripting" /> è impostato con un'istanza di tipo non COMVisible.</exception>
    </member>
    <member name="M:System.Windows.Controls.WebBrowser.Refresh">
      <summary>Consente di ricaricare la pagina corrente.</summary>
      <exception cref="T:System.ObjectDisposedException">L'istanza di <see cref="T:System.Windows.Controls.WebBrowser" /> non è più valida.</exception>
      <exception cref="T:System.InvalidOperationException">Impossibile recuperare un riferimento all'oggetto WebBrowser nativo sottostante.</exception>
    </member>
    <member name="M:System.Windows.Controls.WebBrowser.Refresh(System.Boolean)">
      <summary>Consente di ricaricare la pagina corrente con convalida della cache facoltativa.</summary>
      <param name="noCache">Specifica se effettuare l'aggiornamento senza convalida della cache.</param>
      <exception cref="T:System.ObjectDisposedException">L'istanza di <see cref="T:System.Windows.Controls.WebBrowser" /> non è più valida.</exception>
      <exception cref="T:System.InvalidOperationException">Impossibile recuperare un riferimento all'oggetto WebBrowser nativo sottostante.</exception>
    </member>
    <member name="P:System.Windows.Controls.WebBrowser.Source">
      <summary>Ottiene o imposta l'oggetto <see cref="T:System.Uri" /> del documento corrente ospitato in <see cref="T:System.Windows.Controls.WebBrowser" />.</summary>
      <returns>
        <see cref="T:System.Uri" /> per il documento HTML corrente.</returns>
      <exception cref="T:System.ObjectDisposedException">L'istanza di <see cref="T:System.Windows.Controls.WebBrowser" /> non è più valida.</exception>
      <exception cref="T:System.InvalidOperationException">Impossibile recuperare un riferimento all'oggetto WebBrowser nativo sottostante.</exception>
      <exception cref="T:System.Security.SecurityException">Navigazione da un'applicazione eseguita in attendibilità parziale a un oggetto <see cref="T:System.Uri" /> che non si trova nel sito di origine.</exception>
    </member>
    <member name="T:System.Windows.Controls.WrapPanel">
      <summary>Posiziona gli elementi figlio in sequenza da sinistra verso destra, interrompendo il contenuto quando viene raggiunto il bordo della casella contenitore e facendolo ripartire dalla riga successiva. L'ordinamento successivo procede in sequenza dall’alto in basso o da destra verso sinistra, a seconda del valore della proprietà <see cref="P:System.Windows.Controls.WrapPanel.Orientation" />.</summary>
    </member>
    <member name="M:System.Windows.Controls.WrapPanel.#ctor">
      <summary>Inizializza una nuova istanza della classe <see cref="T:System.Windows.Controls.WrapPanel" />.</summary>
    </member>
    <member name="M:System.Windows.Controls.WrapPanel.ArrangeOverride(System.Windows.Size)">
      <summary>Dispone il contenuto di un elemento <see cref="T:System.Windows.Controls.WrapPanel" />.</summary>
      <returns>
        <see cref="T:System.Windows.Size" /> rappresenta la dimensione disposta dell'elemento <see cref="T:System.Windows.Controls.WrapPanel" /> e degli elementi figlio.</returns>
      <param name="finalSize">
        <see cref="T:System.Windows.Size" /> che questo elemento deve utilizzare per disporre gli elementi figlio.</param>
    </member>
    <member name="P:System.Windows.Controls.WrapPanel.ItemHeight">
      <summary>Ottiene o imposta un valore che specifica l'altezza di tutti gli elementi contenuti all'interno di un <see cref="T:System.Windows.Controls.WrapPanel" />.</summary>
      <returns>Il <see cref="T:System.Double" /> che rappresenta l'altezza uniforme di tutti gli elementi contenuti all'interno di <see cref="T:System.Windows.Controls.WrapPanel" />. Il valore predefinito è <see cref="F:System.Double.NaN" />.</returns>
    </member>
    <member name="F:System.Windows.Controls.WrapPanel.ItemHeightProperty">
      <summary>Identifica <see cref="P:System.Windows.Controls.WrapPanel.ItemHeight" />   proprietà di dipendenza.</summary>
      <returns>Identificatore di <see cref="P:System.Windows.Controls.WrapPanel.ItemHeight" />   proprietà di dipendenza.</returns>
    </member>
    <member name="P:System.Windows.Controls.WrapPanel.ItemWidth">
      <summary>Ottiene o imposta un valore che specifica la larghezza di tutti gli elementi contenuti all'interno di un <see cref="T:System.Windows.Controls.WrapPanel" />.</summary>
      <returns>Un <see cref="T:System.Double" /> che rappresenta la larghezza uniforme di tutti gli elementi contenuti all'interno di <see cref="T:System.Windows.Controls.WrapPanel" />. Il valore predefinito è <see cref="F:System.Double.NaN" />.</returns>
    </member>
    <member name="F:System.Windows.Controls.WrapPanel.ItemWidthProperty">
      <summary>Identifica <see cref="P:System.Windows.Controls.WrapPanel.ItemWidth" />   proprietà di dipendenza.</summary>
      <returns>Identificatore di <see cref="P:System.Windows.Controls.WrapPanel.ItemWidth" />   proprietà di dipendenza.</returns>
    </member>
    <member name="M:System.Windows.Controls.WrapPanel.MeasureOverride(System.Windows.Size)">
      <summary>Misura gli elementi figlio di un oggetto <see cref="T:System